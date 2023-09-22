#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &original_arr)
{
    for (int i = 1; i < original_arr.size(); i++)
    {
        int j = i;
        for (; j >= 1; j--)
        {
            if (original_arr[j - 1] < original_arr[j])
            {
                swap(original_arr[j - 1], original_arr[j]);
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
    vector<int> original_arr = {2, 10, 8, 4, 12, 3};
    cout << "Array Before\n";
    display(original_arr);
    insertion_sort(original_arr);
    cout << "Array After\n";
    display(original_arr);
}