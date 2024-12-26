#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y,t;
    scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d",&x,&y);
        int a=abs(x-y)-1;
        int ans=x+y+a;
        printf("%d\n",ans);
    }
    return 0;
}
