#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        int segments = 0;
        bool inSegment = false;

        for (int i = 0; i < N; ++i) {
            if (S[i] == '0') {
                if (!inSegment) {
                    segments++;
                    inSegment = true;
                }
            } else {
                inSegment = false;
            }
        }

        cout << min(segments,1) << "\n";
    }

    return 0;
}
