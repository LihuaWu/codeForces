#include <time.h>

#include <iostream>
#include <mutex>

#include "PerfTest.h"

std::mutex funcMutex;
void sayHello() {
    std::lock_guard<std::mutex> lck(funcMutex);
    //std::cout << "hello, how are u.\n";
    usleep(5000);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "perf confFile.\n";
        return 0;
    }
    muyu::PerfTest pf(argv[1]);
    pf.setTask(sayHello);
    pf.run();
    return 0;
}
