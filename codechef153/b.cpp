#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll r, g, b;
        cin >> r >> g >> b;
        ll max_butterflies = max({r, g, b});
        if (max_butterflies <= (r + g + b) / 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
