#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
int dfn[1001],low[1001],entry[1001][4],sum,deep,color[1001],cost[1001],degree[1001];
bool vis[1001],e[1001][1001];
stack<int>s;
vector<int>g[1001];
void tarjan(int u)
{
	dfn[u]=low[u]=++deep;
	vis[u]=true;
	s.push(u);
	int len=g[u].size();
	for(int i=0;i<len;i++)
	{
		int v=g[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
		{
			if(vis[v])
			{
				low[u]=min(low[u],low[v]);
			}
		}
	}
	if(dfn[u]==low[u])
	{
		color[u]=++sum;
		vis[u]=false;
		cost[sum]=min(cost[sum],entry[u][3]);
		while(s.top()!=u)
		{
			color[s.top()]=sum;
			cost[sum]=min(cost[sum],entry[s.top()][3]);
			vis[s.top()]=false;
			s.pop();
		}
		s.pop();
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(cost,inf,sizeof(cost));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&entry[i][0],&entry[i][1],&entry[i][2],&entry[i][3]);
		for(int j=1;j<i;j++)
		{
			long long dis=(entry[i][0]-entry[j][0])*(long long)(entry[i][0]-entry[j][0])+(entry[i][1]-entry[j][1])*(long long)(entry[i][1]-entry[j][1]);
			if(entry[i][2]*(long long)entry[i][2]>=dis)
			{
				g[i].push_back(j);
			}
			if(entry[j][2]*(long long)entry[j][2]>=dis)
			{
				g[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int len=g[i].size();
		for(int j=0;j<len;j++)
		{
			if(color[i]==color[g[i][j]])
			{
				continue;
			}
			if(!e[color[i]][color[g[i][j]]])
			{
				degree[color[g[i][j]]]++;
				e[color[i]][color[g[i][j]]]=true;
			}
		}
	}
	int total=0;
	for(int i=1;i<=sum;i++)
	{
		if(!degree[i])
		{
			total+=cost[i];
		}
	}
	printf("%d",total);
	return 0;
}
