#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int score = 0;
        for (int i = 0; i < n ; i++)
        {
            score*=2;
            if(s[i]==0)
            {
                score=1;
            }
        }

        cout << score << endl;
    }

    return 0;
}
