#include <iostream>
#include <vector>
using namespace std;

int countWaysToDestroyAllWalls(const vector<int>& A) {
    int N = A.size();
    vector<int> left_max(N, 0), right_max(N, 0);

    // Compute maximum damage coverage to the right from each position
    int max_right = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > 0) {
            max_right = max(max_right, i + A[i]);
        }
        right_max[i] = max_right;
    }

    // Compute maximum damage coverage to the left from each position
    int max_left = N - 1;
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] > 0) {
            max_left = min(max_left, i - A[i]);
        }
        left_max[i] = max_left;
    }

    // Count the valid ways
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0) {
            bool can_destroy_all = false;

            // Check if placing the ball and pushing right will destroy all walls
            if (right_max[i] >= N - 1) {
                can_destroy_all = true;
            }

            // Check if placing the ball and pushing left will destroy all walls
            if (left_max[i] <= 0) {
                can_destroy_all = true;
            }

            if (can_destroy_all) {
                ++count;
            }
        }
    }

    return count;
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << countWaysToDestroyAllWalls(A) << endl;
    }

    return 0;
}
