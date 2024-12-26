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
        map<int,int> mp;
        for(int i=0; i<n;i++)
        {
            cin >> a[i];
            mp[a[i]]=max(mp[a[i]],i+1);
        }
        ll sum=0;
        for (auto& [key, value] : mp)
            sum += value;
        cout << sum<< '\n';
    }
    return 0;
}
