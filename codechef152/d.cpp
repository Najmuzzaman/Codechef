#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int MAXVAL = 3;

vector<int> count1(MAXN + 1, 0);
vector<int> count2(MAXN + 1, 0);
vector<int> count3(MAXN + 1, 0);

void preprocess(const vector<int>& A, int N) {
    for (int i = 1; i <= N; ++i) {
        count1[i] = count1[i - 1] + (A[i - 1] == 1);
        count2[i] = count2[i - 1] + (A[i - 1] == 2);
        count3[i] = count3[i - 1] + (A[i - 1] == 3);
    }
}

bool isBeautiful(int L, int R) {
    int num1 = count1[R] - count1[L - 1];
    int num2 = count2[R] - count2[L - 1];
    int num3 = count3[R] - count3[L - 1];
    int length = R - L + 1;

    if (length == 1) return true;
    if (length == 2) return (num1 > 0 && num2 > 0) || (num1 > 0 && num3 > 0) || (num2 > 0 && num3 > 0);
    if (length == 3) return (num1 > 0 && num2 > 0 && num3 > 0);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        preprocess(A, N);

        while (Q--)
        {
            int L, R;
            cin >> L >> R;
            cout << (isBeautiful(L, R) ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}
