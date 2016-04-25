#include <time.h>
#include <unistd.h>

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

int numThreads = 15;
int maxReq = 10000;
int totalReq = 0;
int allReq = 0;
bool active_flag = false;
bool overlimit_flag = false;
bool canceldone_flag = false;
bool needReset = true;
bool waiting = true;
int periodReq = 0;
bool notified = false;

std::mutex mtx, active_mtx, print_mtx;

std::mutex reset_mtx, work_mtx, compute_mtx;
std::condition_variable reset_cv, work_cv;
std::condition_variable compute_cv;
std::mutex func_mtx;

using namespace std::chrono;

void displayCount();

void func() {
    {
        std::unique_lock<std::mutex> lck(func_mtx);
    }
    usleep(50000);
}

milliseconds Milliseconds() {
    return duration_cast< milliseconds >(
        system_clock::now().time_since_epoch());
}

bool active() {
    std::unique_lock<std::mutex>  lck(active_mtx);
    return active_flag;
}

std::string CurrentTime(); 

std::string CurrentTime() {
    auto tt = system_clock::to_time_t (system_clock::now()); 
    auto timeinfo = localtime (&tt);
    char buff[80];
    strftime (buff,80,"%Y-%m-%d %H:%M:%S",timeinfo);
    return std::string(buff);
}

void print_time(const std::string& msg) {
    std::unique_lock<std::mutex> lck(print_mtx);
    std::cout << msg  << " : "<< CurrentTime() << "\n";
}

int printInfo(const std::string& msg) {
    std::cout << msg << " : " << periodReq << " " << totalReq << "\n";
    return 0;
}

void displayCount() {
    printInfo(CurrentTime());
}

void compute() {
    milliseconds start; 
    waiting = false;
    work_cv.notify_all();
    while(true) {
        start = Milliseconds();
        std::unique_lock<std::mutex> lck(compute_mtx);
        while (!notified) {
            compute_cv.wait_for(lck, milliseconds(1000));
            break;
        }
        waiting  = true;
        milliseconds delta = Milliseconds() - start;
        if (delta < milliseconds(1000)) {
            compute_cv.wait_for(lck, milliseconds(1000) - delta);
        }
        totalReq += periodReq;
        displayCount();
        {
            std::unique_lock<std::mutex> lck(mtx);
            periodReq = 0;
            notified = false;
        }
        waiting = false;
        work_cv.notify_all();
    }
}

void worker(int id) { 
    while (active()) {
        { 
            std::unique_lock<std::mutex> lck(work_mtx);
            while(waiting) { work_cv.wait(lck); }
        }
        func();
        std::unique_lock<std::mutex> lck(mtx);
        periodReq += 1;
        if (periodReq >= maxReq) {
            if(!notified) {
                compute_cv.notify_one(); 
                notified = true;
            }
        }
    }
}

int main() {
    active_flag = true;
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; i++) {
        threads.push_back(std::thread(worker, i));
    } 
    threads.push_back(std::thread(compute));
    for (auto & th : threads) th.join();
    return 0; 
}
