#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y, int n, int m, const vector<vector<char>>& grid)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

int bfs(int n, int m, const vector<vector<char>>& grid, vector<vector<int>>& dist)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (is_valid(nx, ny, n, m, grid) && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist[n - 1][m - 1];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<char>> grid(n, vector<char>(m));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
                cin >>grid[i][j];
        }
        vector<vector<int>> dist1(n, vector<int>(m, INF));
        vector<vector<int>> dist2(n, vector<int>(m, INF));
        int d1 = bfs(n, m, grid, dist1);
        if (d1 == INF)
        {
            cout<<-1<<"\n";
            continue;
        }
        grid[0][0] = '#';
        int d2 = bfs(n, m, grid, dist2);
        if (d2 == INF)
            cout << -1 << "\n";
        else
            cout << min(d1, d2) << "\n";
    }
    return 0;
}
