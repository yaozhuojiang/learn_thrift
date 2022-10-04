#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

void task(int a, int b, int &ret)
{
    std::unique_lock<std::mutex> lck(mtx);
    int sqrt_a = a * a;
    int sqrt_b = b * b;
    ret = sqrt_a + sqrt_b;
    cv.notify_one();
    // std::this_thread::sleep_for(std::chrono::microseconds(2000000));
}

void task1(int a, int b, std::promise<int> &ret)
{
    int sqrt_a = a * a;
    int sqrt_b = b * b;
    ret.set_value(sqrt_a + sqrt_b);
}

void task2(int a, std::future<int> &b, std::promise<int> &ret)
{
    int sqrt_a = a * a;
    int sqrt_b = b.get() * 2;
    ret.set_value(sqrt_a + sqrt_b);
}


int main()
{
    // int res = 0;
    // std::thread t(task, 1, 2, std::ref(res));
    // std::unique_lock<std::mutex> lck(mtx);
    // cv.wait(lck);
    // std::cout << res << std::endl;
    // t.join();

    // std::promise<int> p;
    // std::future<int> f = p.get_future();
    // std::thread t(task1, 1, 2, std::ref(p));
    // std::cout << f.get() << std::endl;
    // t.join();

    std::promise<int> p_in;
    std::future<int> f_in = p_in.get_future();
    std::promise<int> p_res;
    std::future<int> f_res = p_res.get_future();
    std::thread t(task2, 1, std::ref(f_in), std::ref(p_res));
    p_in.set_value(3);
    std::cout << f_res.get() << std::endl;
    t.join();
    return 0;
}