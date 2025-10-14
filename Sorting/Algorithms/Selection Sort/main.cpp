#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

int find_min(vector<int> &vec, int start, int size)
{
    if (start >= size || start < 0 || size > vec.size())
        return -1;

    int min = start;
    for (int i = start + 1; i < size; i++)
    {
        if (vec[i] < vec[min])
            min = i;
    }
    return min;
}

int main()
{
    vector<int> vec = {5, 8, 1, 7, 2, 9, 4, 6, 0, 11, 3};
    int size = vec.size();

    for (int i = 0; i < size; i++)
    {
        int minIdx = find_min(vec, i, size);
        if (minIdx != -1)
            swap(vec[i], vec[minIdx]);
    }

    for (auto e : vec)
        print(e);

    return 0;
}