#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {10, 7, 12, 8, 7, 10, 0, 1, 5, 5, 0};
    if (vec.empty())
    {
        cout << "Array is empty!\n";
        return 0;
    }

    int maxElem = *max_element(vec.begin(), vec.end());
    int minElem = *min_element(vec.begin(), vec.end());
    vector<int> freqs(maxElem - minElem + 1);

    for (const int &n : vec)
        freqs[n - minElem]++;

    int idx = 0;
    for (int i = 0; i < freqs.size(); i++)
    {
        while (freqs[i] > 0)
        {
            vec[idx++] = i + minElem;
            freqs[i]--;
        }
    }

    for (int &n : vec)
        cout << n << " ";

    cout << "\n";

    return 0;
}