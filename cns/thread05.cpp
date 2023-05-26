/*Example for thread where a shared resource is utilised using mutex*/
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static int shared_value = 0;
std::mutex mLock;

void shared_value_increment1()
{
    mLock.lock();
    shared_value += 1;
    mLock.unlock();
}
void shared_value_increment2()
{
    mLock.lock();
    shared_value += 2;
    mLock.unlock();
}
int main()
{
    std::thread th1(shared_value_increment1);
    std::thread th2(shared_value_increment2);
    th1.join();
    th2.join();
    std::cout << "Hello from main thread" << std::endl;
    std::cout << "Shared Value = " << shared_value << std::endl;
    return 0;
}