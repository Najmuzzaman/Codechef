#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll k,const vector<ll>& v,ll n, ll x)
{
    ll low=v[0]-k;
    ll high=v[0]+k;
    for(int i=1;i<n;i++)
    {
        ll cul=max(v[i]-k,low);
        ll cuh=min(v[i]+k,high+x);
        if(cul>cuh)
        {
            return false;
        }
        low=cul;
        high=cuh;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll>v(n);
        for (int i=0;i<n;i++)
            cin >> v[i];
        ll l=0;
        ll r=2e9;
        ll ans=0;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,v,n,x))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        vector<ll> c(n);
        c[0]=v[0]+ans;
        c[0]=max(c[0],v[0]-ans);
        for(int i=1;i<n;i++)
        {
            c[i]=min(c[i-1]+x,v[i]+ans);
        }
        ll ma=0;
        for(int i=0;i<n;i++)
            ma=max(ma,abs(c[i]-v[i]));

        cout<<ma<<endl;
        for(int i=0;i<n;i++)
            cout<<c[i]<<' ';
        cout<<endl;
    }

    return 0;
}
