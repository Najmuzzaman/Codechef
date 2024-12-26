#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
vector<int> tree[MAXN];
int color[MAXN];
int dist[3][MAXN];
int n;

void bfs(int col, vector<int> &startVertices)
{
    queue<int> q;
    memset(dist[col], -1, sizeof(int) * (n + 1));

    for (int u : startVertices)
    {
        q.push(u);
        dist[col][u] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : tree[u])
        {
            if (dist[col][v] == -1)
            {
                dist[col][v] = dist[col][u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            tree[i].clear();

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int cnt=0;
        for (int i = 1; i <= n; i++)
        {
            if(tree[i].size()==1)
                cnt++;
        }
        ll ccnt=n-cnt;
        ll totalBeauty= ccnt*2+cnt*3;

        cout << totalBeauty << endl;
    }

    return 0;
}
