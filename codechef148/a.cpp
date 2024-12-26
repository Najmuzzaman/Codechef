#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        int total_slices_eaten = 0;

        while (A != B) {
            if (A > B) {
                int eat = (A + 1) / 2; // half of Alice's slices, rounded up
                A -= eat;
                total_slices_eaten += eat;
            } else {
                int eat = (B + 1) / 2; // half of Bob's slices, rounded up
                B -= eat;
                total_slices_eaten += eat;
            }
        }

        cout << total_slices_eaten << endl;
    }

    return 0;
}
