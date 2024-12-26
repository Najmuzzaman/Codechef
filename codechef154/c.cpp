#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200006];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans=0;
        bool allk=true;
        bool trygcd=true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != k)
            {
                allk = false;
                break;
            }
        }
        if (allk)
            ans = 0;
        else
        {
            int l=-1, r=n;
            for(int i=0;i<n;i++)
            {
                if(a[i]!=k)
                {
                    if(l==-1)
                        l=i;
                    r=i;
                }
            }
            if(l==r)
                ans=1;
            else
            {
                bool x=true;
                bool y=true;
                ll f= a[l]^k;
                for(int i=l;i<=r;i++)
                {
                    if(a[i]%k!=0) y=false;
                    if( (a[i]^k) != f) x=false;
                }

                if(x || y)
                    ans=1;
                else
                    ans=2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
