#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> cards(n);
        vector<int> second(n);
        vector<int> maxs(n);
        for(int i=0; i<n;i++)
            cin >> cards[i];
        int aliceMax=0,aliceIndex=0;
        int bobMax=0,bobIndex=0;
        for(int i = 0; i < n; i++)
        {
            cin >> second[i];
            if(cards[i]>aliceMax)
            {
                bobMax=aliceMax;
                bobIndex=aliceIndex;
                aliceMax=cards[i];
                aliceIndex=i;
            }
            else if(cards[i]>bobMax)
            {
                bobMax=cards[i];
                bobIndex=i;
            }
        }
        int bobMaxWithValue=max(aliceMax,second[aliceIndex]);
        int bobMaxWithOutValue=max(bobMax,second[bobIndex]);
        bool aliceWins=false;
        for(int i=0;i<n;i++)
        {
            aliceMax=max(cards[i],second[i]);
            if( (i==aliceIndex && aliceMax>bobMaxWithOutValue)||(i!=aliceIndex && aliceMax>bobMaxWithValue) )
            {
                aliceWins=true;
                break;
            }
        }
        cout << (aliceWins ? "Yes" : "No") << '\n';
    }
    return 0;
}
