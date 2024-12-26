#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n=1,a,b;
        string s;
        cin>>n>>a>>b;
        vector<int> v(n);
        cin>>s;
        int x=0, y=0;
        bool possible=false;
        for(int i=0;i<n;i++)
        {
            if (s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            else if (s[i] == 'L') x--;
            else if(s[i] == 'R') x++;

            int dis = abs(a-x) + abs(b-y);
            if(dis <= (i+1) && dis%2 == (i+1)%2)
            {
                possible = true;
				break;
            }
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}
