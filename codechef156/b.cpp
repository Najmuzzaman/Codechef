#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int oddCount=0, evenCount=0;
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
            if (a[i]%2==1) oddCount++;
            else evenCount++;
        }
        int ans = 0;
        if(oddCount>0)
        {
            ans=1+evenCount;
            oddCount--;
            ans+=oddCount/2;
        }

        cout << ans << endl;
    }

    return 0;
}

