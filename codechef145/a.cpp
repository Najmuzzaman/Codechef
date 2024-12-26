#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while (T--)
        {
        int N, D;
        cin >> N >> D;
        vector<int> A(N);

        for (int i = 0; i < N; ++i)
            cin >> A[i];


        // We start with the close-range gun
        bool isCloseRange = true;
        int switches = 0;

        for (int i = 0; i < N; ++i)
        {
            if (isCloseRange && A[i] > D)
            {
                // Need to switch to long-range gun
                isCloseRange = false;
                switches++;
            } else if (!isCloseRange && A[i] <= D)
            {
                // Need to switch to close-range gun
                isCloseRange = true;
                switches++;
            }
        }

        cout << switches << endl;
    }

    return 0;
}
