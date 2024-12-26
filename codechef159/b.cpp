#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >>n>>x;
        vector<int> a(n),b(n),need(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            need[i]=b[i]-a[i];
        }
        sort(need.begin(),need.end());
        int a_win=0;
        for(int i=0;i<n;i++)
        {
            if(need[i]<0)
                a_win++;
            else
            {
                int ne=need[i]+1;
                if(x>=ne)
                {
                    a_win++;
                    x-=ne;
                }
            }
        }
        n=n/2;
        if(n<a_win)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}

