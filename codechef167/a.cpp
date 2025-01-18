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
        string s;
        cin >> n >> s;
        if (s.find('0') != string::npos && s.find('1') != string::npos)
            cout<<"1\n";
        else
             cout<<n<<"\n";
    }
    return 0;
}
