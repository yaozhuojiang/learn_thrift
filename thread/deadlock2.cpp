#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
const int N = 1e6;

int val = 0;
std::mutex mtx[2];
void solve1(int fi, int se)
{
    std::lock_guard<std::mutex> lock1(mtx[fi]);
    std::this_thread::sleep_for(std::chrono::microseconds(2000));
    std::lock_guard<std::mutex> lock2(mtx[se]);
    // mtx[fi].lock();
    // mtx[se].lock();
    std::cout << "############### run ###################" << std::endl;
    // mtx[fi].unlock();
    // mtx[se].unlock();
}
void deadlock2()
{
    std::thread t1(solve1, 1, 2);
    std::thread t2(solve1, 2, 1);
    t1.join();
    t2.join();
    std::cout << val << std::endl;
}

int main()
{
    deadlock2();
    return 0;
}
