#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val, bool lb)
{
    cout << val << (lb ? "\n" : " ");
}

void bubble_sort(int (&arr)[3][3], int size)
{
    int currentElem, nextElem;

    for (int i = 0; i < size - 1; i++)
    {
        bool didSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            currentElem = *(&arr[0][0] + j);
            nextElem = *(&arr[0][0] + j + 1);

            if (currentElem > nextElem)
            {
                swap(*(&arr[0][0] + j), *(&arr[0][0] + j + 1));
                didSwap = true;
            }
        }

        if (!didSwap)
            break;
    }
}

int main()
{
    int arr[3][3] = {
        {6, 0, 5},
        {8, 4, 3},
        {1, 2, 7}};

    int rows = sizeof(arr) / sizeof(arr[0]),
        cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    bubble_sort(arr, rows * cols);

    for (auto &row : arr)
    {
        for (auto &elem : row)
            print(elem, 0);
        cout << endl;
    }

    return 0;
}