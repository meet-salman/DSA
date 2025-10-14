#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

int main()
{
    vector<int> vec = {5, 8, 1, 7, 2, 9, 4, 6, 0, 3};
    int size = vec.size();

    for (int i = 0; i < size - 1; i++)
    {
        bool didSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
            break;
    }

    for (auto e : vec)
        print(e);

    return 0;
}