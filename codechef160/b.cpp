#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> b(n);
        int z=0,o=0;
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
            if(b[i]==1 && i<n-1)
                o++;
            if(b[i]==0 && i>0)
                z++;
        }
        cout<<n+min(o+z,n-1)<<endl;
    }

    return 0;
}
