#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin >>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll s=k*(n-i-1)+a[i];
            ans=max(ans,s);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
