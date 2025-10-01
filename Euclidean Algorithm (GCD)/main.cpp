#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &val)
{
    cout << val << "\n";
}

int euclidean_algo(int a, int b)
{
    if (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;

        return euclidean_algo(a, b);
    }
    return a;
}

int main()
{

    int a,
        b;

    cin >> a >> b;

    int gcd = euclidean_algo(abs(a), abs(b));
    print(gcd);

    return 0;
}