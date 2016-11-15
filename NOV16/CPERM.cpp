#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll modulospecial(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    while(b)
    {
        if(b&1) x=(x*y)%mod;
        y=(y*y)%mod;
        b>>=1;
    }
    return x%mod;
}

int main()
{
	int t;
	ll n,ans,mod=1e9+7;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%lld",&n);
	    if(n==1) {printf("0\n");}
	    else
        {
            ans=modulospecial(2,n-1,mod);
            printf("%lld\n",(ans+mod-2)%mod);
        }
	}
	return 0;
}
