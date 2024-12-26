#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;

vector<int> tree[MAXN + 1];
int level[MAXN + 1];

void bfs(int root, int n)
{
    queue<int> q;
    q.push(root);
    fill(level, level + n + 1, -1);
    level[root] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : tree[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int solve(int n, int k)
{
    bfs(1, n);

    int myLevel = level[n];

    return myLevel + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            tree[i].clear();

        for (int i=0;i<n-1;i++)
        {
            int u,v;
            cin >>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        cout << solve(n, k) << '\n';
    }
    return 0;
}
