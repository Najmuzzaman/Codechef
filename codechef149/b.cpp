#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        int operations = 0;

        for (int i = 0; i < N; ++i)
            cin >> A[i];

        int f=0;
        while(A[f]<=0 && f <= N)
            f++;

        int l=N-1;
        while(A[l]<=0 && l >= 0)
            l--;

        if(l<=f)
            operations=0;
        else
        {
            for(int i=f;i<=l;i++)
            {
                if (A[i] < 0)
                    ++operations;
            }
        }
        cout << operations << endl;
    }

    return 0;
}
