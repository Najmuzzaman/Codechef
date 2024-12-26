#include <bits/stdc++.h>
using namespace std;

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
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        if (is_sorted(p.begin(), p.end()))
        {
            cout << 0 << '\n';
            continue;
        }

        // To find the minimum K, we should consider misplaced elements
        vector<pair<int, int>> indexedpermutation;
        for (int i = 0; i < n; i++) {
            indexedpermutation.push_back({p[i], i});
        }

        sort(indexedpermutation.begin(), indexedpermutation.end());

        int minK = 0;

        vector<bool> visited(n, false);  // To track visited indices
        for (int i = 0; i < n; i++)
        {
            if (visited[i] || indexedpermutation[i].second == i)
                continue;

            int maxElement = 0;
            int cycleSize = 0;
            int current = i;

            while (!visited[current])
            {
                visited[current] = true;
                maxElement = max(maxElement, p[current]);
                current = indexedpermutation[current].second;
                cycleSize++;
            }

            if (cycleSize > 1)
            {
                minK = max(minK, maxElement+1);
            }
        }

        cout << minK << '\n';
    }

    return 0;
}
