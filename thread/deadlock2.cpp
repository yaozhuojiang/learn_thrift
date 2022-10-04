#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
const int N = 1e6;

int val = 0;
std::mutex mtx[2];
void solve1(int fi, int se)
{
    // mtx[fi].lock();
    // std::this_thread::sleep_for(std::chrono::microseconds(2000));
    // mtx[se].lock();
    // 解决方法
    std::lock(mtx[fi], mtx[se]);
    std::cout << "############### run ###################" << std::endl;
    mtx[fi].unlock();
    mtx[se].unlock();
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
