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
        vector<ll> v(n);
        ll first;
        cin >> v[0];
        first=v[0];
        for (int i = 1; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        if (first == v[0])
            cout << first + (v[1] - first) / 2 << endl;
        else if (first == v[n - 1])
            cout << 1000000 - first + 1 + (first - v[n - 2]) / 2 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == first)
                {
                    cout << (v[i + 1] - first) / 2 + (first - v[i - 1]) / 2 +1<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}
