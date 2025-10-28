#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> vec = {4, 2, 2, 8, 3, 3, 1};
    if (vec.empty())
    {
        cout << "Array is empty!\n";
        return 0;
    }

    int maxSize = *max_element(vec.begin(), vec.end());
    vector<int> freqs(maxSize + 1, 0);

    for (auto &n : vec)
        freqs[n]++;

    int idx = 0;
    for (int i = 0; i < freqs.size(); i++)
    {
        while (freqs[i] > 0)
        {
            vec[idx++] = i;
            freqs[i]--;
        }
    }

    for (int &n : vec)
        cout << n << " ";

    cout << "\n";

    return 0;
}