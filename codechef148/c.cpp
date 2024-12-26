#include <bits/stdc++.h>
using namespace std;

// Function to check if the counts for 1, 2, and 3 are all positive
bool containsAll(int count1, int count2, int count3) {
    return count1 > 0 && count2 > 0 && count3 > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> prefix1(n + 1, 0), prefix2(n + 1, 0), prefix3(n + 1, 0);

        // Read input and construct prefix sum arrays
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            prefix1[i + 1] = prefix1[i] + (v[i] == 1 ? 1 : 0);
            prefix2[i + 1] = prefix2[i] + (v[i] == 2 ? 1 : 0);
            prefix3[i + 1] = prefix3[i] + (v[i] == 3 ? 1 : 0);
        }

        int count = 0;
        // Check subarrays using the prefix sums
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int count1 = prefix1[j + 1] - prefix1[i];
                int count2 = prefix2[j + 1] - prefix2[i];
                int count3 = prefix3[j + 1] - prefix3[i];
                if (containsAll(count1, count2, count3)) {
                    ++count;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}
