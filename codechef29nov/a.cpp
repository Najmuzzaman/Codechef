#include <iostream>
#include <vector>


int checkvowel(char a)
{
	if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
		return 1;
	else
		return 0;
}

int checknotvowel(char a)
{
	if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
		return 0;
	else
		return 1;
}

int main() {
	int t; //"CODETOWN"
	scanf("%d",&t);
	while (t--) {
		string s;
		scanf("%s", &s);
		int ans = 0;
		for (int i = 0; i < 8; i++)
		{
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7)
				ans += checknotvowel(s[i]);
			else
				ans += checkvowel(s[i]);
		}

		printf("%s\n", ans == 8 ? "YES" : "NO");
	}

	return 0;
}
