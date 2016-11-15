#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[1000];
int main()
{
    int t,n,i,j;
    ll val,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ans=1000000000000000009;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                val=(a[i]*a[j])/__gcd(a[i],a[j]);
                if(val<ans)
                    ans=val;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
