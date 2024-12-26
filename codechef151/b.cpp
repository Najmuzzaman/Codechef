#include <bits/stdc++.h>

using namespace std;

ll main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll count_zeros = 0, count_ones = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count_zeros++;
            else
                count_ones++;
        }
        ll ans=0;
        for(ll k=1;k<=n;k++)
        {
            if( (k>=count_zeros && (k-count_zeros)%2==0) || (k>=count_ones && (k-count_ones)%2==0) )
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
