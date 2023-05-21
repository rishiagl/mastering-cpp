#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>

template <typename T>
void printvector(std::vector<T> &arr)
{
    std::cout << "Printing Values\n";
    for (auto value : arr)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
int main()
{

    srand((unsigned)time(NULL));
    std::vector<int> arr;
    std::cout << "Generating a vector with 10 random numbers\n";
    int random;
    for (int i = 0; i < 10; i++)
    {
        random = rand();
        arr.push_back(random % 10);
    }
    printvector<int>(arr);

    auto func = printvector<int>;

    std::sort(arr.begin(), arr.end(),
              [](int a, int b) 
              {
                  return a > b;
              });

    printvector<int>(arr);
}