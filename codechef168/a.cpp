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
        int n;
        string s1,s2;
        cin >> n >> s1>>s2;
        bool flag=true;
        int cnt=0;
        for(int i=0;i<n&&flag;i++)
        {
            if(s1[i]=='1' && s2[i]=='1')
                cnt++;
            else if(s1[i]=='0' && s2[i]=='1')
                flag=false;
            else if(s1[i]=='1' && s2[i]=='0')
                flag=false;
        }
        if (!flag)
            cout<<"YES\n";
        else if(cnt%2==1)
             cout<<"YES\n";
        else
             cout<<"NO\n";
    }
    return 0;
}
