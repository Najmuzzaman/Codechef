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
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = num;
                num++;
                if (num > n)
                    num = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
                reverse(grid[i].begin(), grid[i].end());
            for (int j = 0; j < n; j++)
                cout<<grid[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
