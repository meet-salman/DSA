#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

int linear_search(vector<int> &vec, int start, int end, int target)
{
    for (int i = start; i <= end; i++)
    {
        if (vec[i] == target)
            return i;
    }
    return -1;
}

int jump_search(vector<int> &vec, int start, int end, int jump, int target)
{
    if (start > end)
        return linear_search(vec, max(0, end - jump + 1), end, target);

    if (vec[start] == target)
        return start;

    if (vec[start] > target)
        return linear_search(vec, max(0, start - jump), start, target);

    return jump_search(vec, start + jump, end, jump, target);
}

int main()
{

    vector<int> vec = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int target = 14;

    int idx = jump_search(vec, 0, vec.size() - 1, sqrt(vec.size()), target);
    print(idx);

    return 0;
};