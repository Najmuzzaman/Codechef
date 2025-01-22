#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m,p;
        cin>>m>>p;
        int re=299-m;
        int ma =(1000-p-m)/21;
        if (ma>re)
            ma=re;
        cout<<ma<<endl;
    }

    return 0;
}
