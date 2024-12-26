#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for (int i=0;i<n;i++)
            cin>>a[i];
        int ans=0,cnt=0;
        int maxV=a[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=maxV)
            {
                maxV=a[i];
                ans = max(ans, cnt);
                cnt=0;
            }
            else
                cnt++;
        }
        ans = max(ans, cnt);
        cout<<ans<<"\n";
    }
    return 0;
}
