#include<cstdio>
#include<cstring>
using namespace std;
int map[1010][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			map[u][v]++;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				printf("%d ",map[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
