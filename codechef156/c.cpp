#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        int minS1 = a[0];
        int maxS1 = a[n-k-1];
        int ss=0;
        if(k==1)
            ss=n-1;
        else
            ss=n-2;
        int minS2 = a[ss];
        int maxS2 = a[n-1];

        int score = minS1 + maxS1 + minS2 + maxS2;

        cout << score << endl;
    }

    return 0;
}
