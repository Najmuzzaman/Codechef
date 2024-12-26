#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 100;
const int MAX_N = 2 * 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N+1);

        // Array of vectors to store positions where each value occurs
        vector<vector<int>> positions(MAX_A + 1);

        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
            positions[A[i]].push_back(i);  // Store the index i where value A[i] occurs
        }

        long long triplet_count = 0;

        // Iterate over all values from 1 to 100 for A[i] and A[k]
        for (int a_i = 1; a_i <= MAX_A; ++a_i) {
            for (int a_k = 1; a_k <= MAX_A; ++a_k) {
                // Now, we have all positions of a_i and a_k in the array
                // positions[a_i] -> contains indices where A[i] == a_i
                // positions[a_k] -> contains indices where A[k] == a_k

                for (int i : positions[a_i])
                {
                    for (int k : positions[a_k])
                    {
                        int dist_i_k = abs(a_i - a_k);
                        for (int j = 1; j <= N; ++j)
                        {
                            int dist_i_j = abs(i - j);
                            int dist_j_k = abs(j - k);
                            if (dist_i_k == dist_i_j + dist_j_k) {
                                ++triplet_count;
                            }
                        }
                    }
                }
            }
        }

        cout << triplet_count << "\n";
    }

    return 0;
}
