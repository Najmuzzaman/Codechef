#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
template <class T> inline T modulospecial(T a,T b,T mod)
{
    T x=1,y=a;
    while(b)
    {
        if(b&1) x=(x*y)%mod;
        y=(y*y)%mod;
        b>>=1;
    }
    return x%mod;
}

ll calculate_probability(int n, int d, const vector<int>& stones)
{
    ll way = (1LL * d * d) % MOD;
    ll win = (1LL * d * (d + 1) / 2) % MOD;
    ll probability = (win * modulospecial(way, MOD-2, MOD)) % MOD;
    return probability;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
       int n, d;
        cin >> n >> d;
        vector<int> stones(n);
        for (int i = 0; i < n; i++)
            cin >> stones[i];
        cout<<calculate_probability(n, d, stones)<<endl;
    }
    return 0;
}
