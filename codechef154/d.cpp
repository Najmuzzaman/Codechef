#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
         for (ll i = 0; i < n; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        vector<pair <ll,ll>> ev;
        for (ll i = 0; i < n - 1; i++)
        {
            ll start = v[i + 1] - v[i] + 1;
            ll end = v[i + 1] + v[i] - 1;
            ev.push_back({start, 1});
            ev.push_back({end + 1, -1});
        }
        sort(ev.begin(), ev.end());
        ll ac = 0, pr = -1, result = 0;
        for (const auto& e : ev)
        {
            ll p = e.first, s = e.second;
            if (pr != -1 && ac > 0)
                result += (p - pr);
            ac += s;
            pr = p;
        }
        cout << result << endl;
    }
    return 0;
}
