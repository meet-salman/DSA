#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val, bool lb)
{
    cout << val << (lb ? "\n" : " ");
}

void sort_rows(vector<vector<int>> &vec, int rowSize)
{
    int row = 0, i, j;

    while (row < rowSize)
    {
        i = 0;
        while (i <= rowSize)
        {
            j = 0;
            while (j <= rowSize)
            {
                if (vec[row][i] > vec[row + 1][j])
                    swap(vec[row][i], vec[row + 1][j]);

                j++;
            }
            i++;
        }
        row++;
    }

    row = 0;
    while (row < rowSize - 1)
    {
        i = 0;
        while (i <= rowSize)
        {
            j = 0;
            while (j <= rowSize)
            {
                if (vec[row][i] > vec[row + 1][j])
                    swap(vec[row][i], vec[row + 1][j]);

                j++;
            }
            i++;
        }
        row++;
    }
}

int main()
{

    vector<vector<int>> vec = {
        {6, 0, 5},
        {8, 4, 3},
        {1, 2, 7}};

    sort_rows(vec, vec[0].size() - 1);

    // After placing elements in correct rows, apply sorting in every raw

    for (auto &row : vec)
    {
        for (auto &elem : row)
            print(elem, 0);
        cout << endl;
    }

    return 0;
}