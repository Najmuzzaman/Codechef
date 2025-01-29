#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> p = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int m[6] = {0, 0, 0, 0, 0, 0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (s[i] != p[j][i % 3])
                    m[j]++;
            }
        }
        sort(m,m+6);
        cout << m[0] << "\n";
    }
    return 0;
}
