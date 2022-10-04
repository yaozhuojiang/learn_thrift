#include <thread>
#include <iostream>
#include <future>

int add(int a, int b)
{
    int sqrt_a = a * a;
    int sqrt_b = b * b;
    return sqrt_a + sqrt_b;
}

int main()
{
    std::future<int> fu = std::async(add, 1, 2);
    std::cout << fu.get() << std::endl;
    return 0;
}

