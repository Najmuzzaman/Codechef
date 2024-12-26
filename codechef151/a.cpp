#include <bits/stdc++.h>
using namespace std;

ll main()
{
    ll T;
    cin >> T;

    while (T--) {
        ll D, X, Y;
        cin >> D >> X >> Y;

        if (Y >= X)
        {
            cout << 0 << endl;
            continue;
        }

        Y*=100;


        bool possible = false;

        for (ll n = 0; n <= 100; n++)
        {
            ll remainingCoins = Y - n*100;
            if (remainingCoins < 0) break; // Chef has no more coins to spend

            // Calculate the discounted membership cost (lleger math)
            ll discountedCost = (X * (100 - n * D));
            // Check if remaining coins are enough to buy the discounted membership
            if (remainingCoins >= discountedCost)
            {
                cout << n << endl;
                possible = true;
                break;
            }
        }

        // If no valid number of sessions was found
        if (!possible)
            cout << -1 << endl;
    }

    return 0;
}
