#include <iostream>
#include <mutex>
#include <thread>
#include <deque>
#include <chrono>
#include <condition_variable>
#include <unistd.h>

const int N = 1e2 + 5;

std::deque<int> q;
std::mutex mtx;
std::condition_variable cv;

void producer()
{
    int i = 1;
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        q.push_back(i++);
        // std::cout << "hello " << i << std::endl;
        cv.notify_one();
        if (i % 100 == 0) sleep(5);
    }
}
void consumer()
{
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        if (q.empty()) {
            std::cout << "#####################33" << std::endl;
            cv.wait(lck);
        }
        if (!q.empty()) {
            int frt = q.front();
            q.pop_front();
            std::cout << frt << std::endl;
        }
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}