#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void quick_sort(vector<int> &arr, int l, int r)
{
    if(r - l <= 1) return;
    int green = l + 1 , yellow = l + 1;
    while(green < r) {
        if(arr[green] < arr[l])
        {
            swap(arr[yellow], arr[green]);
            yellow++;
        }
        green++;
    }
    swap(arr[l], arr[yellow - 1]);
    display(arr);
    quick_sort(arr, l, yellow - 1);
    quick_sort(arr, yellow, r);
}

int main()
{
    vector<int> arr = {42, 32, 22, 78, 63, 57, 91, 13};
    cout << "Array Before\n";
    display(arr);
    quick_sort(arr, 0, arr.size());
    cout << "Array After\n";
    display(arr);
}