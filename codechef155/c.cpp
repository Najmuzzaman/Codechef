#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                    cout << 3 << " ";
                else if(j>=n && i==0)
                    cout << 3 << " ";
                 else if(i>=m && j==0)
                    cout << 3 << " ";
                else
                    cout << 2 << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
