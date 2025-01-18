#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool check(vector<int> a)
{
    map<int,vector<int>> bit;
    for(int i=0;i<n;i++)
        bit[__builtin_popcount(a[i])].push_back(i);

    for(auto& [b, bi] : bit)
    {
        vector<int> v;
       for(int i=0;i<bi.size();i++)
            v.push_back(a[bi[i]]);
        sort(v.begin(),v.end());
        for(int i=0;i<bi.size();i++)
            a[bi[i]]=v[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >>n;
        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin>>a[i];

        if(check(a))
            cout<<"Yes\n";
        else
             cout<<"No\n";
    }
    return 0;
}
