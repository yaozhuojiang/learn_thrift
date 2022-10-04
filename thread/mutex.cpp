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
        // mtx.lock();
        val += 1;
        val -= 1;
        // mtx.unlock();
    }
}
void protect_val()
{
    std::thread t1(solve1);
    std::thread t2(solve1);
    t1.join();
    t2.join();
    std::cout << val << std::endl;
}

int main()
{
    protect_val();
    return 0;
}
