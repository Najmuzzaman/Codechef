#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Function to determine if ball `a` collides with ball `b`
bool check(pair<ll, ll> a, pair<ll, ll> b) {
    // Check if ball `a` reaches the hole after ball `b`
    return a.first * b.second > b.first * a.second;
}

ll main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;
        vector<pair<ll, ll>> pos(N);

        // Read positions
        for (ll i = 0; i < N; i++)
            cin >> pos[i].first;

        // Read speeds
        for (ll i = 0; i < N; i++)
            cin >> pos[i].second;

        // Sort balls by position
        sort(pos.begin(), pos.end());

        stack<ll> st;

        // Process each ball
        for (ll i = 0; i < N; i++) {
            // While there is a collision with the ball at the top of the stack
            while (!st.empty() && check(pos[st.top()], pos[i])) {
                st.pop();
            }
            // Push the current ball onto the stack
            st.push(i);
        }

        // Output the number of balls that reach the hole
        cout << st.size() << "\n";
    }

    return 0;
}
