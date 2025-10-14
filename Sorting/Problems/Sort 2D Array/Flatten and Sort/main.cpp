#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val, bool lb)
{
    cout << val << (lb ? "\n" : " ");
}

void bubble_sort(vector<int> &vec1, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool didSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (vec1[j] > vec1[j + 1])
            {
                swap(vec1[j], vec1[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
            break;
    }
}

int main()
{

    vector<vector<int>> vec = {
        {6, 0, 5},
        {8, 4, 3},
        {1, 2, 7}};

    // Storing as 1D
    vector<int> vec1;
    for (auto &row : vec)
        for (auto &elem : row)
            vec1.push_back(elem);

    // Sorting in 1D
    bubble_sort(vec1, vec1.size());

    // Updating sorted elems in 2D using 1D
    int idx = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            vec[i][j] = vec1[idx++];
    }

    // Display Sorted 2D
    for (auto &row : vec)
    {
        for (auto &elem : row)
            print(elem, 0);
        cout << endl;
    }

    return 0;
}