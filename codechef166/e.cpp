#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
vector<int> sieve(int l)
{
    vector<int> prime(l + 1);
    iota(prime.begin(), prime.end(), 0); // Smallest prime factor

    for (int i = 2; i * i <= l; i++)
    {
        if (prime[i] == i) {
            for (int j = i * i; j <= l; j += i)
            {
                if (prime[j] == j)
                    prime[j] = i;
            }
        }
    }
    return prime;
}

ll nod(const unordered_map<int, int>& primeCounts) {
    ll divisors = 1;
    for (auto& [prime, count] : primeCounts)
        divisors = divisors * (count + 1) % MOD;
    return divisors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> prime = sieve(100009);

    unordered_map<int, int> mPrime;
    for (int i = 2; i <= m; i++)
    {
        int num = i;
        while (num > 1)
        {
            mPrime[prime[num]]++;
            num /= prime[num];
        }
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> rPrime = mPrime;
        int num = a[i];

        while (num > 1)
        {
            rPrime[prime[num]]++;
            num /= prime[num];
        }
        result[i] = nod(rPrime);
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
