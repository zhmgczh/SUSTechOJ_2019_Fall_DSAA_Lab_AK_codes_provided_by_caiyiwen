#pragma GCC optimize(2)
#include<cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		char t[n+1],p[m+1];
		scanf("%s%s",t,p);
		int index=-1;
		for(int i=0;i<n;i++)
		{
			if(t[i]=='*')
			{
				index=i;
				break;
			}
		}
		bool ok=true;
		if(index==-1)
		{
			if(n==m)
			{
				for(int i=0;i<n;i++)
				{
					if(t[i]!=p[i])
					{
						ok=false;
						break;
					}
				}
			}
			else
			{
				ok=false;
			}
		}
		else
		{
			if(n>m+1)
			{
				ok=false;
			}
			else
			{
				for(int i=0;i<index;i++)
				{
					if(t[i]!=p[i])
					{
						ok=false;
						break;
					}
				}
			}
			if(ok)
			{
				for(int i=m-1;n-m+i>index;i--)
				{
					if(p[i]!=t[n-m+i])
					{
						ok=false;
						break;
					}
				}
			}
		}
		if(ok)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
