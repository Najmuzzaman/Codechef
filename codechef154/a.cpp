#include <bits/stdc++.h>
using namespace std;
int ar[1001];
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int sum=0;
        int i;
        for (i = 0; i < n; i++)
            cin >> ar[i];
        for (i = 0; i < n; i++)
        {
            sum+=ar[i];
            if(sum>k)
            {
                break;
            }
        }
        cout<<i<<endl;
    }

    return 0;
}
