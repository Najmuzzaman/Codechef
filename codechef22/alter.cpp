#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort the array B in non-decreasing order
        sort(B.begin(), B.end());

        // Initialize array A with all zeros
        vector<int> A(N, 0);

        // Set the first half of A to the values (B[i] + B[N/2 + i]) and the absolute difference
        for (int i = 0; i < N / 2; ++i) {
            A[i] = B[i] + B[N / 2 + i];
            A[N / 2 + i] = abs(B[i] - B[N / 2 + i]);
        }

        // Sort the array A in non-decreasing order to get the maximum possible sum
        //sort(A.begin(), A.end(), greater<int>());

        // Output the array A with the maximum possible sum
        for (int i = 0; i < N; ++i) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
