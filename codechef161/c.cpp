#include <bits/stdc++.h>
using namespace std;


bool isFeasible(const vector<int>& a, int n, int k, int maxDiff)
{
    int changes = 0;
    int low = a[0] - maxDiff;
    int high = a[0] + maxDiff;

    for(int i=1;i<n;i++)
    {
        int newLow = max(low, a[i]-maxDiff);
        int newHigh = min(high, a[i]+maxDiff);
        if (newLow > newHigh)
        {
            changes++;
            newLow=a[i]-maxDiff;
            newHigh=a[i]+maxDiff;
        }
        low=newLow;
        high=newHigh;
        if(changes>k) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        for (int i = 0; i <n;i++)
            cin >> a[i];
        int left = 0, right = 1e9, result = 1e9;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isFeasible(a, n, k, mid))
            {
                result = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << result << '\n';
    }

    return 0;
}
