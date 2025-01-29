#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin >>k>>n;
        string s;
        cin>>s;
        int ans=0;
        for(char c:s)
        {
            if(c=='S')
                ans++;
        }
        if(ans>=n)
            cout<<k<<"\n";
        else
            cout<<k+(n-ans-1)<<"\n";
    }
    return 0;
}
