#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
const int N = 1e6;

int val = 0;
std::mutex mtx;
void solve1()
{
    for (int i = 1; i <= N; i++) {
        // 解决方法：使用 lock_guard 或者 unique_lock 
        // std::lock_guard<std::mutex> lck(mtx);
        // std::unique_lock<std::mutex> lck(mtx);
        mtx.lock();
        val += 1;
        // 中途意外推出
        if (val == 1) return ;
        val -= 1;
        mtx.unlock();
    }
}
void deadlock1()
{
    std::thread t1(solve1);
    std::thread t2(solve1);
    t1.join();
    t2.join();
    std::cout << val << std::endl;
}

int main()
{
    deadlock1();
    return 0;
}
