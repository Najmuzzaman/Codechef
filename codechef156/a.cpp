#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i=0;i<n;i++)
            cin >> a[i];
        int sw=a[n-1];
        int p=n;
        for (int i=n-2;i>=0;i--)
        {
            if (a[i]<=sw/2)
                p--;
            else
                break;
        }
        cout<<p<<endl;
    }

    return 0;
}
