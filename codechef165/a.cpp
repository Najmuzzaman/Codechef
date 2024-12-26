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
        cin>>n;

        vector<int> a(n);
        for(int i=0; i<n;i++)
            cin >> a[i];

        sort(a.begin(),a.end());
        ll sum=0;
        for(int i = 0; i < n; i++)
        {
            int s=a[i]-i;
            sum+=(s<0?0:s);
        }
        cout << sum<< '\n';
    }
    return 0;
}
