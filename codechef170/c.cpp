#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll total_sum =0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total_sum+=a[i];
        }
        sort(a.begin(),a.end());
        ll ans = total_sum;
        for (int i = 0; i < n; i++)
        {
            total_sum-=a[i];
            ll s=i+1;
            ans = max(ans,total_sum+s*s);
        }
        ans = max(ans, n*n);
        cout<<ans<<"\n";
    }
    return 0;
}
