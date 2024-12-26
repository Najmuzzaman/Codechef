#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        unordered_map<int, int> pairCount;

        // Count pairs (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xorValue = a[i] ^ a[j];
                pairCount[xorValue]++;
            }
        }

        ll totalQuadruples = 0;

        // Calculate quadruples from pairs
        for (const auto &entry : pairCount)
        {
            int cnt = entry.second;
            if(cnt>1)
            totalQuadruples += 4LL * cnt * (cnt - 1); // Combinations of pairs
        }

        printf("%lld\n", totalQuadruples) ; // Each quadruple can be arranged in 8 ways
    }

    return 0;
}
