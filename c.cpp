#include <iostream>

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        std::cout << "[";
        for (int j = 1; j <= 50; j++)
        {
            if (j == 50)
                std::cout << j;
            else
                std::cout << j << ",";
        }
        if (i == 50)
            std::cout << "]";
        else
            std::cout << "],";
    }
}