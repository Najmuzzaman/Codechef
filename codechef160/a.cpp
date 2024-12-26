#include <bits/stdc++.h>
using namespace std;

int minDeletionsToPalindrome(string &s, int n) {
    // dp[i][j] will store the length of longest palindromic subsequence in s[i...j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // A single character is always a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the dp table for substrings of length 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // The LPS length for the whole string is dp[0][n-1]
    int lps = dp[0][n - 1];
    return n - lps;  // The minimum deletions required to make the string a palindrome
}

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n;  // Length of the string
        string s;  // The string
        cin >> n >> s;

        // Check if the string is already a palindrome
        string revS = s;
        reverse(revS.begin(), revS.end());

        if (s == revS) {
            cout << 0 << endl;  // Already a palindrome
        } else {
            int min_deletions = minDeletionsToPalindrome(s, n);
            // We can always make it a palindrome with at least one operation if it's not already one
            cout << min_deletions << endl;
        }
    }

    return 0;
}
