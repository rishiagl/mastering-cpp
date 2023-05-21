/*Example for thread where a shared resource is utilised using mutex*/
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static int shared_value = 0;
std::mutex mLock;

void shared_value_increment()
{
    mLock.lock();
    shared_value += 1;
    mLock.unlock();
}
int main()
{
    std::vector<std::thread> t_list;
    for (int i = 0; i < 100; i++)
    {
        t_list.push_back(std::thread(shared_value_increment));
    }
    for (int i = 0; i < 100; i++)
    {
        t_list[i].join();
    }
    std::cout << "Hello from main thread" << std::endl;
    std::cout << "Shared Value = " << shared_value << std::endl;
    return 0;
}