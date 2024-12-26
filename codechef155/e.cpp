#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> b(n), a(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        a[0] = 0;
        ll sumA =0;
        ll maxA = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = b[i] - sumA;
            sumA += a[i];
            maxA = max(maxA, a[i]);
        }
        a[0]=maxA;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
