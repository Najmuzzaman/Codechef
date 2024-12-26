#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void countDivisors(int n, int &e, int &o)
{
    e = 0;
    o = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                e++;
            else
                o++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int e, o;
        countDivisors(n, e, o);
        if (e > o)
            cout << 1 << endl;
        else if (e < o)
            cout << -1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
