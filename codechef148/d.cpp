#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!
int  main()
{
 ios_base::sync_with_stdio();
 cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        int n=1,m=0;
        string s;
        cin>>n>>m;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];
        priority_queue<int, vector<int> , greater<int>> mH (v.begin(),v.end());

        for(int i=0; i<m; i++)
        {
            int sm = mH.top();
            mH.pop();
            sm = sm*2;
            mH.push(sm);
        }

        int res = 0;
        while(!mH.empty()){
            res += mH.top();
            res %= MOD;
            mH.pop();
        }
        cout<<res<<endl;
    }
    return 0;
}
