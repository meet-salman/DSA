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

    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j])
        {
            swap(vec[j - 1], vec[j]);
            j--;
        }
    }

    for (auto e : vec)
        print(e);

    return 0;
}