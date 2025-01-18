#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sum_achive(vector<ll>& p, vector<ll>& ne, ll target)
{
    ll a=0, n=0,s=0,m=0;
    while(a<p.size()|| n< ne.size())
    {
        while(s+(a<p.size()?p[a]:0)>target)
        {
            if (n < ne.size())
            {
                s += ne[n];
                m = max(m, s);
            }
            else
                return false;
            s = max(0LL, s);
            n++;
        }
        if(a<p.size())
        {
            s += p[a];
            m = max(m, s);
            a++;
        }
        else if (n < ne.size())
        {
            s += ne[n];
            m = max(m, s);
            s = max(0LL, s);
            n++;
        }
    }
    return m <= target;
}

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
        vector<ll> a(n), p, ne;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] >= 0) p.push_back(a[i]);
            else ne.push_back(a[i]);
        }
        if(p.empty())
        {
            cout <<"0\n";
            continue;
        }
        ll l =*max_element(p.begin(), p.end());
        ll r =accumulate(p.begin(), p.end(), 0LL);
        ll ans=r;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if(sum_achive(p, ne, mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout <<ans<<endl;
    }
    return 0;
}
