// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id (int id) {
  std::unique_lock<std::mutex> lck(mtx);
  std::cout << (lck ? "Own" : "Not own") << " a lock.\n";
  while (!ready) cv.wait(lck);
  // ...
  std::cout << "thread " << id << '\n';
}

void go() {
  std::unique_lock<std::mutex> lck(mtx);
  //std::cout << "go acquire lock.\n";
  //ready = true;
  cv.notify_all();
}

int main ()
{
  std::cout << "locking mutex.\n";
  mtx.lock();
  std::cout << "locked.\n";
  mtx.lock();
  std::cout << "locked again.\n";

  return 0;

  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_id,i);

  std::cout << "10 threads ready to race...\n";
  go();                       // go!

  for (auto& th : threads) th.join();

  return 0;
}
