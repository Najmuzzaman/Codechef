#include <bits/stdc++.h>
using namespace std;
int ans[200010];
bool prie[2000010];
inline void seive()
{
    int   i,j,k;
    memset(prie,true,sizeof(prie));
    prie[0]=0;
    prie[1]=0;
    k=0;
    for(i=1;i*i<=2000010;i++)
    {
        if(prie[i])
        {
            p[k++]=i;
            for(j=i*i;j <=2000010;j+=i)
                prie[j]=false;
        }
    }
}

int nod(int t)
{
    int count=0;
    int i;
    if(!t) return 0;
    for(i=2;i*2<=t;i++)
    {
        if(t%i==0)
            count=max(ans[i],count);
    }
    return count;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    seive();
    memset(ans,0,sizeof(ans));
    for(int i=2;i<=90000;i++)
    {
        int s=0;
        if(!prie[i])
            s=nod(i);
        ans[i]=s+1;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int ma=0;
        cin >> N;
        for(int i=2;i<=N;i++)
        {
            if(ans[i]==0)
            {
                int s=0;
                if(!prie[i])
                    s=nod(i);
                ans[i]=s+1;
            }
            ma=max(ans[i],ma);
        }

        ma++;
        printf("%d\n%d",ma,ma);
        for (int i = 2; i <=N; ++i)
            printf(" %d",ans[i]);
        printf("\n");
    }

    return 0;
}
