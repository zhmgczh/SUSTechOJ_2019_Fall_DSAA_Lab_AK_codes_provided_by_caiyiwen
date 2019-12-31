#include<cstdio>
#include<vector>
using namespace std;
vector<int>g[(int)1e5+10];
int color[(int)1e5+10],red_total,blue_total,res;
struct status
{
	int red,blue;
};
status dfs(int u,int far)
{
	status current;
	if(color[u]==1)
	{
		current.red=1;
		current.blue=0;
	}
	else if(color[u]==2)
	{
		current.blue=1;
		current.red=0;
	}
	else
	{
		current.red=current.blue=0;
	}
	int len=g[u].size();
	status next;
	for(int i=0;i<len;++i)
	{
		if(g[u][i]!=far)
		{
			next=dfs(g[u][i],u);
			current.red+=next.red;
			current.blue+=next.blue;
		}
	}
	if(far!=-1)
	{
		if(current.red==red_total&&current.blue==0)
		{
			++res;
		}
		else if(current.blue==blue_total&&current.red==0)
		{
			++res;
		}
	}
	return current;
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
			g[i].clear();
		}
		int u,v;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		red_total=blue_total=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&color[i]);
			if(color[i]==1)
			{
				++red_total;
			}
			else if(color[i]==2)
			{
				++blue_total;
			}
		}
		res=0;
		dfs(1,-1);
		printf("%d\n",res);
	}
	return 0;
}
