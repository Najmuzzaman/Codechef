#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int dp[101][5001];

ll binomialCoeff(ll n, ll k)
{
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k);
    ll res = 1;
    for (ll i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll numBlack = n / 2;
        ll result = binomialCoeff((n * n + 1) / 2, numBlack);
        if(result%2) result++;
        cout << result << endl;
    }

    return 0;
}
