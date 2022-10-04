#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <atomic>
const int N = 1e6;

std::atomic<int> val(0);

void solve1()
{
    for (int i = 1; i <= N; i++) {
        val += 1;
        val -= 1;
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

