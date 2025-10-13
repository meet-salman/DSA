#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int size = vec.size(), left = 0, right = size - 1, target = 33, idx = -1;

    while (left <= right)
    {
        int midIdx = left + ((right - left) / 2);

        if (vec[midIdx] == target)
        {
            idx = midIdx;
            break;
        }
        else if (vec[midIdx] > target)
            right = midIdx - 1;
        else
            left = midIdx + 1;
    }

    print(idx);

    return 0;
}