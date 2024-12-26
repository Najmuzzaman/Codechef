#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_set<ll> s;
        vector<int> ans(n);
        ll a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            while(s.find(a) != s.end())
            {
                s.erase(s.find(a));
                a*=2;
            }
            s.insert(a);
            ans[i]=s.size();
        }
        for(int i=0;i<n;i++)
            cout << ans[i] << " ";
        cout <<endl;
    }

    return 0;
}
