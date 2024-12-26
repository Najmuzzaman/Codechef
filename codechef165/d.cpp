#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll min_steps(ll d, ll K)
{
    if (K <=d) return d;
    ll full_blocks = d / K;
    ll remaining = d % K;
    return d + full_blocks;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll x1, y1, z1, x2, y2, z2, K;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> K;

        ll dx = abs(x2 - x1);
        ll dy = abs(y2 - y1);
        ll dz = abs(z2 - z1);

        ll steps_x = min_steps(dx, K);
        ll steps_y = min_steps(dy, K);
        ll steps_z = min_steps(dz, K);

        ll total_steps = steps_x + steps_y + steps_z;

        cout << total_steps << "\n";
    }
    return 0;
}
