#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        vector<pair<ll, ll>> a_b(n);
        ll sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            a_b[i]=make_pair(a[i]-b[i],b[i]);
            sum += b[i];
        }
        sort(a_b.begin(), a_b.end());
        ll ans = sum;
        sum += a_b[0].first;
        for (int i = 1; i < n; i++)
        {
            sum += a_b[i].first;
            ans = min(ans, sum);
        }

        cout << ans << endl;
    }

    return 0;
}
