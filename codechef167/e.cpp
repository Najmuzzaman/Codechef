#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a;
        ll pre=0;
        ll ans=0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            pre += a;
            ans += abs(pre);
        }
        cout<<ans<<endl;
    }
    return 0;
}
