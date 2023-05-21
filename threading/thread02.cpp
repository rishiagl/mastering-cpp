/*Example to create multiple threads*/
#include <iostream>
#include <thread>
#include <vector>

int main()
{

    auto lambda = [](int x)
    {
        std::cout << "Hello from thread with id" << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };
    std::vector<std::thread> t_list;
    for (int i = 0; i < 10; i++)
    {
        t_list.push_back(std::thread(lambda, 100));
    }
    for (int i = 0; i < 10; i++)
    {
        t_list[i].join();
    }
    std::cout << "Hello from main thread" << std::endl;
    return 0;
}