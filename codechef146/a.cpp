#include <bits/stdc++.h>
using namespace std;

bool canEndWithSameScore(int A, int B, int C, int M) {
    int scores[3] = {A, B, C};
    sort(scores, scores + 3);
    int minScore = scores[0], midScore = scores[1], maxScore = scores[2];

    int frist=midScore-minScore;
    int second=maxScore-midScore;

    int totalPossiblePoints = minScore + M;

    if (frist <= M || second<= M)
        return true;
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C, M;
        cin >> A >> B >> C >> M;
        if (canEndWithSameScore(A, B, C, M)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
