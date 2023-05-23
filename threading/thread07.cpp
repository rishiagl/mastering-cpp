/*Example for thread using atomic*/
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

static std::atomic<int> shared_value = 0;

void shared_value_increment()
{
    shared_value++;
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