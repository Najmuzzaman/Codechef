#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> skills(16);
        for (int i = 0; i < 16; ++i)
            cin >> skills[i];

        // Make a copy of the skills vector to sort and determine rankings
        vector<int> sorted_skills = skills;
        sort(sorted_skills.begin(), sorted_skills.end(), greater<int>());

        int ans[16];
        int ranks=4;
        for (int i = 0; i < 16; ++i)
        {
            skill_to_wins[sorted_skills[i]] = ranks;
            if(i==0)
                ranks--;
            if(i==8)
                ranks--;
            if(i==12)
                ranks--;
            if(i==14)
                ranks--;
        }


        // Output the results for this test case
        for (int i = 0; i < 16; ++i) {
            cout << skill_to_wins[skills[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}
