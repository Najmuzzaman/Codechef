#include <bits/stdc++.h>
using namespace std;


int calculateProfit(int n, vector<int>& p)
{
    int fixed_points = 0;
    for (int i = 0; i < n; ++i)
        if (p[i] == i + 1)
            fixed_points++;

    if (fixed_points == n) return fixed_points;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> p(n);
        vector<int> sortedP(n);
        for (int i=0; i< n; i++)
        {
            cin>>p[i];
            sortedP[i]=p[i];
        }
        sort(sortedP.begin(), sortedP.end());

        bool matches = false;
        for(int i=0;i<n;i++)
        {
            if (p[i] != sortedP[i])
                matches=true;
        }
        if(matches)
        {
            cout<<n<<"\n";
        }
        else
        {
            matches=true;
            for(int i=0;i<n&&matches;i++)
            {
                if(p[i]==i+1)
                    matches=false;
            }
            if(matches)
                 cout<<n-1<<"\n";
            else
                 cout<<n-2<<"\n";
        }
    }
    return 0;
}
