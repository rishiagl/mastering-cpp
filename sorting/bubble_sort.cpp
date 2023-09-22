#include <bits/stdc++.h>

using namespace std;

void bubble(vector<int> &arr)
{
    for (int j = 0; j < arr.size(); j++)
    {
        for (int i = 0; i < arr.size() - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
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
    vector<int> arr = {10, 17, 3, 28};
    cout << "Array Before\n";
    display(arr);
    bubble(arr);
    cout << "Array After\n";
    display(arr);
}