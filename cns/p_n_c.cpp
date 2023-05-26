#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::vector<int> buffer;
int buffer_size = 5;
int i = 0;

void consumer_thread()
{
    std::cout << "Consumption thread started" << std::endl;
    int data;
    while (true)
    {
        {
            // wrap the mutex around unique lock and acquire it
            std::unique_lock lk(m);

            // wait untill i get greater than 0
            cv.wait(lk, []()
                    {   if( i > 0)
                        return true;
                    else return false; });

            // consume data from buffer
            data = buffer[i - 1];
            buffer.pop_back();
            i--;

            //printing the value of i to see concurrency in action.
            std::cout << i << std::endl;

            // delay by 0.1 second
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // release lock and notify a producer
            lk.unlock();
            cv.notify_one();
        }

        // print data to std output
        // std::cout << data << std::endl;
    }
}

void producer_thread()
{
    std::cout << "Production thread started" << std::endl;
    int data;
    while (true)
    {
        // produce a data
        data = rand() % 10;

        {
            // wrap the mutex around unique lock and acquire it
            std::unique_lock lk(m);

            // wait untill i get lessor than buffer_size
            cv.wait(lk, []()
                    {   if(i < buffer_size)
                            return true;
                        else return false; });

            // Add data to buffer
            buffer.push_back(data);
            i++;

            // delay by 0.1 second
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // release lock and notify a consumer
            lk.unlock();
            cv.notify_all();
        }
    }
}
int main()
{
    std::cout << "Main Thread started with thread id: " << std::this_thread::get_id() << std::endl;

    // start producer thread
    std::thread pth(&producer_thread);

    // start consumer thread
    std::thread cth(&consumer_thread);

    // delay by 2 second
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::terminate();

    // We can create multiple producers and consumers and still the synchornisation will be maintained.
}