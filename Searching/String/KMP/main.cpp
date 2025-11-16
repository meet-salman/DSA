#include <bits/stdc++.h>
using namespace std;

vector<int> compute_lps_array(string patt, int pSize)
{
    vector<int> lps(pSize, 0);
    int pre = 0, suff = 1;

    while (suff < pSize)
    {
        if (patt[pre] == patt[suff])
        {
            pre++;
            lps[suff] = pre;
            suff++;
        }
        else
        {
            if (pre > 0)
                pre = lps[pre - 1];
            else
                suff++;
        }
    }

    for (auto e : lps)
        cout << e << " ";

    cout << endl;

    return lps;
}

void kmp_search(string text, string patt)
{

    int tSize = text.size(),
        pSize = patt.size();

    vector<int> lps = compute_lps_array(patt, pSize);

    int i = 0, j = 0;
    while (i < tSize)
    {
        if (patt[j] == text[i])
        {
            i++;
            j++;

            if (j == pSize)
            {
                cout << i - j << " ";
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    string text = "AABAACAADAABAABAA",
           patt = "AABAA";

    kmp_search(text, patt);

    return 0;
}
