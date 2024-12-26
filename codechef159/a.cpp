#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int  p[1000001]; //prime array
bool prie[1000001]; //
inline void seive()
{
    int i,j,k;
    memset(prie,true,sizeof(prie));
    prie[0]=0;
    prie[1]=0;
    k=0;
    for(i=1;i*i<=1000000;i++)
    {
        if(prie[i])
        {
            p[k++]=i;
            for(j=i*i;j <=1000000;j+=i)
                prie[j]=false;
        }
    }
   for(i=1001;i<=1000000;i+=2)
   {
       if(prie[i])
            p[k++]=i;
   }
}


template <class T> inline T sod(T t)
{
    T ans=0;
    bool flag;
    if(!t) return ans;
    for(int i=0;p[i]*p[i]<=t;i++)
    {
        while(t%p[i]==0)
        {
            t/=p[i];
            ans++;
        }
        if(t==1)
           break;
    }
    if(t!=1)
        ans++;
    return ans;
}

int main()
{
    seive();
    int t;
    cin >> t;
    while (t--)
    {
        ll k,h;
        cin >>h>>k;
        int max_monsters = 0;
        ll i=1;
        ll ans=sod(h);
        while(i<=k)
        {
            i<<=1;
            ans++;
        }
        i/=2;
        ans--;
        cout<<ans<<endl;
    }
    return 0;
}
