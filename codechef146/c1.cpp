#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;


int countWaysHelper(vector<int>& A, int pos, int dir) {
    int n = A.size();
    if (pos < 0 || pos >= n) {
        return 0;
    }
    if (A[pos] == 0) {
        return 0;
    }
    A[pos]--;
    if (A[pos] == 0) {
        int left = countWaysHelper(A, pos - 1, -1);
        int right = countWaysHelper(A, pos + 1, 1);
        A[pos]++;
        return (left + right + 1) % MOD;
    } else {
        int next = countWaysHelper(A, pos + dir, dir);
        A[pos]++;
        return next;
    }
}

int countWays(vector<int>& A) {
    int n = A.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
            ans = (ans + countWaysHelper(A, i, 1) + countWaysHelper(A, i, -1)) % MOD;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << countWays(A) << endl;
    }
    return 0;
}
