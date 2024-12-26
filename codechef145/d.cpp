#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD=1000000007;
ll dp[500005];
ll computeSqingSum(int N)
{
    ll sum = 0;
    ll contrib = 0;

    for (int i = 1; i <= N; ++i)
    {
        contrib = (contrib + (ll)i * i % MOD) % MOD;
        sum = (sum + contrib) % MOD;
    }
    return dp[N]=sum;
}

int main()
{
    int t,n;
    cin >> t;
    memset(dp,0,sizeof(dp));
    while(t--)
    {
        cin >> n;
        if(dp[n])
            cout << dp[n] << "\n";
        else
            cout << computeSqingSum(n)<< "\n";
    }
    return 0;
}
