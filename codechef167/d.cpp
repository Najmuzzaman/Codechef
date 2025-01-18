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
        int i = 0, j = n / 2;
        for (int x = 1; x <= n * n+1; x++)
        {
            grid[i][j] = x;
            int ii = (i - 1 +n) % n;
            int jj = (j + 1) % n;
            if (grid[ii][jj] != 0)
            {
                ii = (i + 1) % n;
                jj = j;
            }
            i = ii;
            j = jj;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cout<<(grid[i][j] - 1) % n + 1<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
