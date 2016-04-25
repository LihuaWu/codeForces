#include <string>
#include <memory>
#include <toml/tom.h>

#include "PerfTest.h"

namespace muyu {

template<typename T>
class Task {
public:
    Task(T* task) noexcept : _pT(task) { _pT->init(); }
    virtual void run() noexcept { _pT->run(); }
    virtual ~Task() noexcept { _pT->destroy(); }
private:
    std::unique_ptr<T> _pT;
};

class PerfTest:PerfTestImpl {
public:
    PerfTestImpl(const std::string& conf) {
        if(_taskType == "normal") {
            _pTask.reset(new Task<Normal>(param));
        }        
        void run();
    }
    ~PerfTestImpl() == default;
private:
    //other functions defined in main.cc
    std::string _taskType;
    std::unique_ptr<Task> _pTask;
};

void PerfTest::PerfTestImpl::run() {
    //main Function in main.cc
}

} //muyu
