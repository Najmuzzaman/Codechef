#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // DP array where dp[i][j] represents the maximum sum of subsequence of length j using first i elements
    vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));

    // Fill the DP array
    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + A[i - 1]);
        }
    }

    int maxSum = 0;

    // Find the maximum sum divisible by the number of elements in the subsequence
    for (int len = 1; len <= N; len++) {
        if (dp[N][len] % len == 0) {
            maxSum = max(maxSum, dp[N][len]);
        }
    }

    cout << maxSum << endl;

    return 0;
}
