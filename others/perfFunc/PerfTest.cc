#include <time.h>
#include <unistd.h>

#include <string>
#include <functional>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#include <toml/toml.h>

#include "PerfTest.h"

using namespace std::chrono;

namespace muyu {

class PerfTest::PerfTestImpl {
public:
    PerfTestImpl(const std::string& conf) {
        std::ifstream ifs(conf);
        toml::ParseResult pr = toml::parse(ifs);
        if (!pr.valid()) {
            std::cout << CurrentTime() << " : " << pr.errorReason << "\n";
            return;
        }
        _conf = pr.value;
        _periodReq = 0;
        _maxReq = _conf.get<int>("config.qps");
    }        
    void setTask(const std::function<void()>& func) noexcept {  
        _task = func;
    } 
    void run() noexcept;
    ~PerfTestImpl() = default;
private:
    //other functions defined in main.cc
    milliseconds Milliseconds() {
    return duration_cast< milliseconds >(
        system_clock::now().time_since_epoch());
}
    void _worker(int id);    
    void _compute();
    std::string CurrentTime() {
        auto tt = system_clock::to_time_t (system_clock::now()); 
        auto timeinfo = localtime (&tt);
        char buff[80];
        strftime (buff,80,"%Y-%m-%d %H:%M:%S",timeinfo);
        return std::string(buff);
    }
    void displayCount() {
        std::cout << CurrentTime() << " : " << _periodReq << " " << _totalReq << "\n";
    }

    int _periodReq, _maxReq, _totalReq;
    bool _waiting, _notified;
    toml::Value _conf;
    std::function<void()> _task;
    std::mutex _work_mtx, _mtx;
    std::condition_variable _work_cv, _compute_cv;
};

void PerfTest::PerfTestImpl::run() noexcept {
    int numThreads = _conf.get<int>("config.threads");
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; i++) {
        threads.push_back(std::thread([this](int i) {
            this->_worker(i);
        }, i));
    }
    threads.push_back(std::thread([this]() {
        this->_compute();
    }));
    for (auto & th : threads) th.join();
}

void PerfTest::PerfTestImpl::_worker(int id) {
    while (true) {
        {
            std::unique_lock<std::mutex> lck(_work_mtx);
            while (_waiting) { _work_cv.wait(lck); }
        }
        _task();
        std::unique_lock<std::mutex> lck(_mtx);
        _periodReq += 1;
        if (_periodReq >= _maxReq) {
            if (!_notified) {
                _compute_cv.notify_one();
                _notified = true;
            }
        }
    }
}

void PerfTest::PerfTestImpl::_compute() {
    milliseconds start;
    std::mutex compute_mtx;
    _waiting = false;
    _work_cv.notify_all();
    while (true) {
        start = Milliseconds();
        std::unique_lock<std::mutex> lck(compute_mtx); 
        while (!_notified) {
            _compute_cv.wait_for(lck, milliseconds(1000));
            break;
        }
        _waiting = true;
        auto delta = Milliseconds() - start;
        if (delta < milliseconds(1000)) {
            _compute_cv.wait_for(lck, milliseconds(1000) - delta);
        }
        _totalReq += _periodReq;
        displayCount();
        {
            std::unique_lock<std::mutex> lck(_mtx);
            _periodReq = 0;
            _notified = false;
        }
        _waiting = false;
        _work_cv.notify_all();
    }
}

void PerfTest::run() noexcept {
    _impl->run();
}

void PerfTest::setTask(const std::function<void()>& func) noexcept {
    _impl->setTask(func);
}

PerfTest::PerfTest(const std::string& conf) noexcept : _impl(new PerfTest::PerfTestImpl(conf)) {}

PerfTest::~PerfTest() noexcept = default;

} //muyu
