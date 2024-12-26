#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        if(n<4)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        int x=1;
        int y=1;
        for(int i=5;i<=n;i++)
        {
            if(i%2==0)
            {
                if(x==y)
                    x++;
                else
                    y++;
            }
        }

        cout<<x*y<<endl;
    }
    return 0;
}
