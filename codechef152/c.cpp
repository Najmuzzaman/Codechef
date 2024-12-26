#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Function to determine if ball `a` collides with ball `b`
bool check(pair<ll, ll> a, pair<ll, ll> b) {
    // Check if ball `a` reaches the hole after ball `b`
    return a.first * b.second > b.first * a.second;
}

ll main() {#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t; // Read number of test cases

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> strings(m);
        for (int i = 0; i < m; i++)
            cin >> strings[i];
        long long total_hamming_sum = 0;
        for (int pos = 0; pos < n; pos++)
        {
            int count0 = 0, count1 = 0,countq=0;
            for (int i = 0; i < m; i++)
            {
                if (strings[i][pos] == '0')
                    count0++;
                else if (strings[i][pos] == '1')
                    count1++;
                else
                    countq++;
            }
            int mi=min(count0,count1);
            int ma=max(count0,count1);
            if(mi+countq<=ma)
            {
                mi+=countq;
            }
            else
            {
               int dif=ma-mi;
               int x=countq-dif;
               mi+=dif;
               mi+=x/2;
               ma+=(x+1)/2;
            }

            total_hamming_sum += 1LL * mi * ma;
        }
        cout << total_hamming_sum << '\n';
    }

    return 0;
}

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
