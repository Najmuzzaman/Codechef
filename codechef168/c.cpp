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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

         map<int, pair<int, int>> mp;

        for (int i = 0; i < n; ++i)
        {
            int v = a[i];
            if (mp.find(v) == mp.end())
                mp[v] = {i, i};
            else
                mp[v].second = i;
        }
        vector<pair<int, int>> in;

        for (const auto& [v, r] : mp)
        {
            int s = r.first, end = r.second;
            if (s != end)
                in.emplace_back(s, end);
        }

        if (in.empty())
        {
            cout<<"0\n";
            continue;
        }

        sort(in.begin(), in.end());

        vector<pair<int, int>> mp1;
        int c_s = in[0].first, c_e = in[0].second;

        for (size_t i = 1; i < in.size(); i++)
        {
            int s = in[i].first, end = in[i].second;
            if (s <= c_e)
                c_e = max(c_e, end);
            else
            {
                mp1.emplace_back(c_s, c_e);
                c_s = s;
                c_e = end;
            }
        }
        mp1.emplace_back(c_s, c_e);
        int cost = 0;
        for (const auto& i : mp1)
        {
            int s = i.first, end = i.second;
            set<int> d(a.begin() + s, a.begin() + end + 1);
            cost += d.size();
        }

        cout<<cost<<'\n';

    }
    return 0;
}
