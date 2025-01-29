#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll inv = 500000004;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll p = 1, q = 1, r = 1;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                p = (p * k) % mod;
        }

        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            if (a[j] != 0)
            {
                if (a[i] != 0 && a[i] != a[j])
                {
                    q = 0;
                    break;
                }
            }
            else if (a[i] == 0)
                q = (q * k) % mod;
        }

        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            if (a[i] != 0 && a[j] != 0)
            {
                if (a[i] != a[j])
                {
                    r = 0;
                    break;
                }
            }
            else if (a[i] == 0 && a[j] == 0)
                r = (r * k) % mod;
        }

        if (n % 2 && a[n / 2] == 0)
            r = (r * k) % mod;

        ll ans = ((2 * p) % mod - q + r + mod) % mod;
        cout << (ans * inv) % mod << endl;
    }
    return 0;
}
