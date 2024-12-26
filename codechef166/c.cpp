#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int finds(int s, const vector<int> &p, vector<bool> &visit)
{
    int c = s;
    int n = 0;
    while (!visit[c])
    {
        visit[c] = true;
        c = p[c] - 1;
        n++;
    }
    return n;
}

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
        vector<int> p(n);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int cnt=0;
        for (int i = 0; i < n; i++)
            cin >> p[i];
        vector<bool> visit(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                minHeap.push(finds(i, p, visit));
                cnt++;
            }
        }
        if (cnt == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll totalCost = 0;
        while (minHeap.size() > 1)
        {
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            totalCost += (a + b);
            minHeap.push(a + b);
        }
        cout << totalCost << endl;
    }
    return 0;
}
