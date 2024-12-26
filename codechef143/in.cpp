#include <bits/stdc++.h>
using namespace std;
bool canConvert(const string &S, const string &T, int N, int K) {
    // Step 3: Count differing positions
    int differingCount = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] != T[i]) {
            differingCount++;
        }
    }
    if(differingCount == K)
        return true;
    if(differingCount%2==0)
        return (differingCount/2 == K);
    else
        return false;
}

int main() {
    freopen("input.txt", "w", stdout);
    int t;
    t=20;
    printf("%d\n",t);
    while (t--) {
        int N, K;
        N=4;
        K=rand()%2;
        K++;
        printf("%d %d\n",N,K);
        string S="",S2="";
        while(N--)
        {
            string SS,SN;
            int b=rand()%2;
            if(b==0)
                SN="0";
            else
                SN="1";
            b=rand()%2;
            if(b==0)
                SS="0";
            else
                SS="1";
            S+=SS;
            S2+=SN;
        }
        cout<<S<<endl<<S2<<endl;
    }

    return 0;
}
