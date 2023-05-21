/* Basic example for usings thread in program and use of join function */
#include <iostream>
#include <thread>

void test(int x)
{
    std::cout << "Hello from thread" << std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
}

int main()
{
    std::thread myThread(&test, 100);
    myThread.join();
    std::cout << "Hello from main thread" << std::endl;
    return 0;
}