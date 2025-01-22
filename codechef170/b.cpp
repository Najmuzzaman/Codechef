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
        int n,a;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0)
                one++;
            else
                two++;
        }
        cout<<max(one,two)<<endl;
    }
    return 0;
}
