/* 
    Thread is a lightweight process that operating-system schedules and runs concurrently with other threads.
    Threads shares the same memory and resources as the main proccess(the parent process).

    Here thread syntax is explained and can be further elaborated to show thread initialization using function pointers and lambda.
    Nessecity of join() should be explained.
*/
#include <iostream>
#include <thread>

int main()
{
    std::cout << "Main Thread id: " << std::this_thread::get_id() << std::endl;

    //Running function test in a new thread.
    std::thread myThread(&test, 100);

    //joining the thread to the current thread it blocks the current thread execution and waits for the called thread to finish its execution to resume.
    myThread.join();

    return 0;
}

void test(int x)
{
    std::cout << "Hello from thread" << std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
}