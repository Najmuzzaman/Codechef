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
        int n,k;
        cin >>n>>k;
        vector<int> a(n);
        vector<int> feq(21);
        vector<int> pre(21),suf(21);
        bool flag=true;
        int kfec=0;
        int mxpre=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            feq[a[i]]++;
            mxpre=max(mxpre,feq[a[i]]);
        }
        kfec=feq[k];
        if(kfec==mxpre)
        {
            cout<<"0\n";
            continue;
        }
        int ct = 0, pt = 0;
        for (int i = 0; i < n; i++)
        {
            pre[a[i]]++;
            ct = max(ct, pre[a[i]]);
            if (ct == pre[k])
            {
                pt = 1;
                break;
            }
        }
        ct=0;
        if(pt==0)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                suf[a[i]]++;
                ct = max(ct, suf[a[i]]);
                if (ct == suf[k])
                {
                    pt = 1;
                    break;
                }
            }
        }
        if(pt)
             cout<<"1\n";
        else
            cout<<"2\n";
    }
    return 0;
}
