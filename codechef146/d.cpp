#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> permutation(n);
        int start = n, end = 1;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                permutation[i] = start--;
            else
                permutation[i] = end++;
        }
        for (int i=0;i<n;i++)
            cout << permutation[i] << " ";
        cout << endl;
    }

    return 0;
}
