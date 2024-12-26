#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);

        int negative_count = 0;
        long long sum = 0;
        int min_abs_value = INT_MAX;

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            if (A[i] < 0) {
                negative_count++;
            }
            sum += abs(A[i]);
            min_abs_value = min(min_abs_value, abs(A[i]));
        }

        if (negative_count % 2 == 1) {
            sum -= 2 * min_abs_value;
        }

        cout << sum << "\n";
    }

    return 0;
}
