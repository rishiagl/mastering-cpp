#include <bits/stdc++.h>

using namespace std;



void selection(vector<int> &arr)
{
    int min_index = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        min_index = 0;
        for (int i = 0; i < arr.size() - j; i++)
        {
            if (arr[i] < arr[min_index])
            {
                min_index = i;
            }
        }
        swap(arr[min_index], arr[arr.size() - 1 - j]);
    }
}

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    vector<int> arr = {2, 10, 8, 4, 12, 3};
    cout << "Array Before\n";
    display(arr);
    selection(arr);
    cout << "Array After\n";
    display(arr);
}