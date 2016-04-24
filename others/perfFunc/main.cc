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

int numThreads = 3;
int maxReq = 100;
int totalReq = 0;
int allReq = 0;
bool active_flag = false;
bool overlimit_flag = false;
bool canceldone_flag = false;

std::mutex mtx, active_mtx, print_mtx;

std::mutex cancellimit_mtx, canceldone_mtx;
std::condition_variable cancellimit_cv, canceldone_cv;

using namespace std::chrono;

void displayCount();

void func() {
    std::mutex func_mtx;
    std::unique_lock<std::mutex> lck(func_mtx);
    //std::cout << "hello func.\n";
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

bool overlimit() {
    std::unique_lock<std::mutex>  lck(mtx);
    return overlimit_flag;
}

std::string CurrentTime(); 

bool canceldone() {
    std::unique_lock<std::mutex> lck(canceldone_mtx);
    return canceldone_flag;
}

void cancellimit() { 
    std::unique_lock<std::mutex> lck(cancellimit_mtx);
    while(!canceldone()) cancellimit_cv.wait_for(lck, seconds(1));
    std::unique_lock<std::mutex> lck(mtx);
    overlimit_flag = false;
    allReq += totalReq;
    displayCount();
    totalReq = 0;
    canceldone_flag = true;
    canceldone_cv.notify_all();
}

void updateCount() {
    std::unique_lock<std::mutex>  lck(mtx);
    totalReq += 1;
    if ( !overlimit_flag && totalReq == maxReq ) {
        overlimit_flag = true;
    }
}

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
    std::unique_lock<std::mutex>  lck(mtx);
    std::cout << msg << " : " << totalReq << " " << allReq << "\n";
    return 0;
}

void displayCount() {
    printInfo(CurrentTime());
}

void worker(int id) { 
    milliseconds startMilli;     
    startMilli = Milliseconds();
    std::condition_variable cv;
    while (active()) {
        milliseconds delta = Milliseconds() - startMilli;
        //print_time(oss.str());
        if(!overlimit() && delta < milliseconds(1000) ) {
            func();
            updateCount();
        } else if (delta >= milliseconds(1000)){
            cancellimit_cv.notify_one();
            std::unique_lock<std::mutex> lck(mtx);
            while (!canceldone()) canceldone_cv.wait_for(lck, seconds(1));
            startMilli = Milliseconds();
        } else {
            {
                std::mutex worker_wait_mtx;
                std::unique_lock<std::mutex> lck(worker_wait_mtx);
                cv.wait_for(lck, milliseconds(1000) - delta);
            }
            cancellimit_cv.notify_one();
            std::unique_lock<std::mutex> lck(canceldone_mtx);
            while (!canceldone()) canceldone_cv.wait_for(lck, seconds(1));
            //cancellimit();
        ////    print_time("before");
         //   cv.wait_for(lck, delta);
         ////   print_time("after");
         //   if(overlimit()) cancellimit();
          startMilli = Milliseconds();
        }//
    }
}

int main() {
    active_flag = true;
    std::vector<std::thread> threads;
    threads.push_back(std::thread(cancellimit));
    for (int i = 0; i < numThreads; i++) {
        threads.push_back(std::thread(worker, i));
    } 
    for (auto & th : threads) th.join();
    return 0; 
}
