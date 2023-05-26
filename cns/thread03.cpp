/*Example for thread where a shared resource is utilised*/
#include <iostream>
#include <thread>
#include <vector>

static int shared_value = 0;

void shared_value_increment()
{
    //increments the value of shared variable by 1
    shared_value += 1;
}
int main()
{
    std::vector<std::thread> t_list;

    //creates 
    for (int i = 0; i < 100; i++)
    {
        //initializes a thread with shared_value_increment funtion
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