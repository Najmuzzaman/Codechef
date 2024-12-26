#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> getRanks(const vector<int>& powers)
{
    int n = powers.size();
    vector<pair<int, int>> indexed_powers(n);
    for (int i = 0; i < n; i++)
        indexed_powers[i] = {powers[i], i};

    sort(indexed_powers.begin(), indexed_powers.end(), greater<>());
    vector<int> ranks(n);
    for (int i = 0; i < n; i++)
        ranks[indexed_powers[i].second] = i + 1;
    return ranks;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b = a;
        sort(b.begin(),b.end());
        int j = 1;
        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
            idx += 1;
            a[i]=n-idx;
        }
        int ans = n;
        for (int i = 0; i < n-1; i++)
        {
            if(abs(a[i]-a[i+1]) < 2)
                ans--;
        }
        cout << ans << endl;
    }

    return 0;
}
