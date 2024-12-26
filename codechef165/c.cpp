#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int>& a, const string& s, const string& p, const string& q)
{
    if (a.empty())
        return true;

    int l = a[0], r = a.back();
    string ss = s.substr(l, r - l + 1);
    reverse(ss.begin(), ss.end());
    string s1 = s.substr(0, l) + ss + s.substr(r + 1);
    return s1 == p || s1 == q;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;

        string p,q;
        for(int i=0;i<n;i++)
        {
            p += (i % 2 == 0) ? '0' : '1';
            q += (i % 2 == 0) ? '1' : '0';
        }
        vector<int> a, b;
        for(int i=0;i<n;i++)
        {
            if (s[i] != p[i])
                a.push_back(i);
            if (s[i] != q[i])
                b.push_back(i);
        }
        if (possible(a, s, p, q) || possible(b, s, p, q))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
