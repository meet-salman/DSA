#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    bool isFound = false;

    for (int i = 0; i < n; i++)
    {
        string text, pattern;
        getline(cin, text);
        getline(cin, pattern);

        int t = text.size(),
            p = pattern.size();

        if (p > t)
        {
            cout << -1 << endl;
            continue;
        }

        isFound = false;
        int idx = 0;
        while (idx <= t - p)
        {
            int j = 0;
            while (j < p && text[idx + j] == pattern[j])
                j++;

            if (j == p)
            {
                isFound = true;
                cout << idx << " ";
            }

            idx++;
        }
        if (!isFound)
            cout << -1;

        cout << endl;
    }

    return 0;
}