#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int t,n,k,i,j;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
        k=n-(n/2);
        for(i=0;i<n;i++)
        {
            bool flag=false;
            for(j=0;j<n;j++)
            {
                if(flag) printf(" ");
                printf("%d",k++);
                flag=true;
                if(j+1==n) k--;
                if(k==n+1) k=1;
            }
            printf("\n");
        }
	}
	return 0;

}
