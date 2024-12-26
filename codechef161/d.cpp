#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i <n;i++)
            cin >> a[i];
        bool change=true;
        while(change)
        {
            change=false;
            for(int i=1;i<n-1;i++)
            {
                if(a[i-1]+a[i+1]== 4)
                {
                    if(a[i]==3)
                    {
                        change=true;
                        a[i]=1;
                    }
                }
            }
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        cout << sum << "\n";
    }
    return 0;
}
