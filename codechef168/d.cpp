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
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        vector<int> p(n + 1, 0);
        for (int i=1; i<=n;i++)
            p[i]=p[i-1]^a[i-1];

        unordered_set<int> s;
        for (int i = 1; i <= n; i++)
        {
            s.insert(a[i-1]);
            s.insert(a[i-1]^p[i-1]);
        }

        int ans = 0;
        for (int xs : s)
        {
            int x = xs;
            int score = 0;
            for (int i = 0; i < n; ++i)
            {
                if (x == a[i])
                    score += x;
                else
                    x ^= a[i];
            }
            ans = max(ans, score);
        }
        cout << ans << endl;
    }
    return 0;
}
