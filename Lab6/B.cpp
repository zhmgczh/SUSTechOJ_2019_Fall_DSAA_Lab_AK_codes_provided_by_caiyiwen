#include<cstdio>
#include<vector>
using namespace std;
vector<int>edge[(int)1e5+10];
int deep[(int)1e5+10];
void dfs(int u,int far,int dep)
{
	deep[u]=dep;
	int len=edge[u].size();
	for(int i=0;i<len;++i)
	{
		if(edge[u][i]!=far)
		{
			dfs(edge[u][i],u,dep+1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			edge[i].clear();
		}
		int a,b;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		dfs(1,-1,0);
		for(int i=1;i<n;++i)
		{
			printf("%d ",deep[i]);
		}
		printf("%d\n",deep[n]);
	}
	return 0;
}
