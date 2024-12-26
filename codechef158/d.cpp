#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for(int i=0;i<n; i++)
            cin >> v[i];

        int xand = v[0];
        for(int i=1;i<n; i++)
            xand &= v[i];

        ll ans = 0;
        ll i = 1;
        ll s=(1LL << 30);
        while(i<=s)
        {
            if (xand & i)
                ans += i;
            i<<=1;
        }
        cout << ans <<endl;
    }

    return 0;
}
