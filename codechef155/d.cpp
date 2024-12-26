#include <bits/stdc++.h>
using namespace std;

int minOperationsToEqual(string S, string T)
{
    set<char> setS(S.begin(), S.end());
    set<char> setT(T.begin(), T.end());

    vector<char> common;
    for (char c : setS)
    {
        if (setT.count(c))
            common.push_back(c);
    }
    if (common.empty()) return -1;

    int operations = 0;

    for (char c : S)
    {
        if (find(common.begin(), common.end(), c) == common.end())
            operations++;
    }

    for (char c : T)
    {
        if (find(common.begin(), common.end(), c) == common.end())
            operations++;
    }

    return operations;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        string S, T;
        cin >> S >> T;

        cout << minOperationsToEqual(S, T) << endl;
    }

    return 0;
}
