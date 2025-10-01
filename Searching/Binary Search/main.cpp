#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

int bnary_search(vector<int> &vec, int start, int end, int target)
{

    if (start > end)
        return -1;

    int midPoint = start + ((end - start) / 2);

    if (vec[midPoint] == target)
        return midPoint;

    if (target > vec[midPoint])
        return bnary_search(vec, midPoint + 1, end, target);
    else
        return bnary_search(vec, start, midPoint - 1, target);
}

int main()
{

    vector<int> vec = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    int target = 5;

    int idx = bnary_search(vec, 0, vec.size() - 1, target);
    print(idx);

    return 0;
};