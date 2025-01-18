#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,x,k;
        string s;
        cin >>n>>x>>k;
        cin >>s;
        int cnt=0;
        int pre_sum=0;
        for (int i =n - 1; i>= 0; i--)
        {
            if (s[i] == '0')
                cnt++;
            else
                pre_sum +=cnt;
        }
        if (pre_sum<=x && pre_sum%k == 0)
            cout<<"1\n";
        else
             cout<<"2\n";
    }
    return 0;
}
