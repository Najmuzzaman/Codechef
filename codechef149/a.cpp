#include <bits/stdc++.h>
using namespace std;

int main()
 {
    int T;
    cin >> T;
    while (T--)
    {
        int A, B, X;
        cin >> A >> B >> X;
        if(A * B <= X * X)
             cout << "0" << endl;
        else if(B <= X * X)
             cout << "1" << endl;
        else if(A <= X * X)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}
