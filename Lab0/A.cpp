#include<cstdio>
using namespace std;
char ma[3][3],s[2];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%s",s);
				ma[i][j]=s[0];
			}
		}
		printf("%c\n",ma[1][1]);
	}
	return 0;
}
