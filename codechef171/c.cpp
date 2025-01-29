#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        vector<ll> ans(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;

        for(int i=0; i<n; i++)
        {
            if(a[i] == 0)
            {
                ans[i] = 0;
                pq.emplace(0, i);
            }
        }
        vector<int> directions = {-1, 1};
        while(!pq.empty())
        {
            pair<ll, int> c = pq.top();
            pq.pop();

            ll c_t = c.first;
            int u = c.second;


            if(c_t > ans[u])
                continue;

            for(auto dir: directions)
            {
                int v = u + dir;
                if(v <0 || v >=n) continue;


                ll r_t;
                if(a[v] == 0)
                    r_t = 0;
                else
                    r_t = (a[v]+p-1)/p;

                ll new_t = max(c_t, r_t);
                if(new_t < ans[v])
                {
                    ans[v] = new_t;
                    pq.emplace(new_t, v);
                }
            }
        }
        if(a[0]==0)
            cout<<"0";
        else
            cout<<ans[0];
        for(int i=1;i<n; i++)
        {
            if(a[i]==0)
                cout<<" 0";
            else
                cout<<" "<<ans[i] ;
        }
        cout<<"\n";
    }
    return 0;
}
