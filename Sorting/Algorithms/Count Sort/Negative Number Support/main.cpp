#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> vec = {-5, -10, 2, -3, -7, 1};

    int minElem = *min_element(vec.begin(), vec.end());
    int maxElem = *max_element(vec.begin(), vec.end());

    vector<int> freqs(maxElem - minElem + 1, 0);

    for (auto &e : vec)
        freqs[e - minElem]++;

    int idx = 0;
    for (int i = 0; i < freqs.size(); i++)
    {
        while (freqs[i])
        {
            vec[idx++] = i + minElem;
            freqs[i]--;
        }
    }

    for (auto &e : vec)
        cout << e << "  ";

    return 0;
}
