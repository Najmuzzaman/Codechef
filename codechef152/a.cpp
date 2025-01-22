#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin >> a[i];

        if (n <= 3)
        {
            cout<< "0" <<endl;
            continue;
        }
        sort(a.begin(), a.end());
        int option1 = a[n-3] - a[0];
        int option2 = a[n-1] - a[2];
        int option3 = a[n-2] - a[1];
        cout<< min({option1, option2, option3})<<endl;
    }

    return 0;
}
