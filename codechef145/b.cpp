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
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        sort(A.begin(),A.end());
        if(A[0]==A[N-1])
            printf("YES\n");
        else if(A[0]==0 && A[N-1]==1)
            printf("YES\n");
        else
        {
            if(A[0]==0)
            {
                int i=0;
                while(A[i]==0 && i<N)
                    i++;
                int cnt=0;
                int b=A[i];
                for(;i<N;i++)
                {
                    if(A[i]!=b)
                        cnt++;
                    if(cnt>1) break;
                }
                if(cnt==0)
                     printf("YES\n");
                else
                     printf("NO\n");
            }
            else
                printf("NO\n");
        }
    }

    return 0;
}
