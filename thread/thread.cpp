#include <iostream>
#include <thread>

void func(int a, int b)
{
    std::cout << "child thread begin!" << std::endl;
    std::cout << a + b << std::endl;
    std::cout << "child thread end!" << std::endl;
}

int main()
{
    std::cout << "main thread begin!" << std::endl;
    std::thread t(func, 1, 2);
    t.join();
    std::cout << "main thread end!" << std::endl;
    return 0;
}