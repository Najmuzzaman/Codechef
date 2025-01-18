#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        // Prefix sums to count '0's and '1's
        vector<int> count_0(n + 1, 0), count_1(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            count_0[i + 1] = count_0[i] + (s[i] == '0');
            count_1[i + 1] = count_1[i] + (s[i] == '1');
        }

        ll total_sum = 0;

        // Optimized computation of total_sum
        for (int i = 0; i < n; i++)
        {
            // Contribution of all subarrays starting from index i
            int num_0 = 0, num_1 = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == '0') num_0++;
                else num_1++;
                total_sum += max(num_0, num_1);
            }
        }

        cout << total_sum << endl;
    }
    return 0;
}
