#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

void merge(vector<int> &vec, int start, int mid, int end)
{
    vector<int> temp;
    int left = start, right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }
    while (right <= end)
    {
        temp.push_back(vec[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        vec[i] = temp[i - start];
    }
}

void merge_sort(vector<int> &vec, int start, int end)
{

    if (start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(vec, start, mid);
    merge_sort(vec, mid + 1, end);

    merge(vec, start, mid, end);
}

int main()
{
    vector<int> vec = {5, 8, 1, 7, 2, 9, 4, 6, 0, 3};
    int size = vec.size();

    merge_sort(vec, 0, size - 1);

    for (auto e : vec)
        print(e);

    return 0;
}