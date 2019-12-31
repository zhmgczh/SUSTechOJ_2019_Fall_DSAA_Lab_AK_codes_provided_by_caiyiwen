#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=(int)4e5+10;
struct Edge
{
	int v,cost;
};
vector<Edge>e[maxn];
int n,m;
bool vis[maxn];
int dist[maxn];
struct qnode
{
	int v;
	int c;
	bool operator<(const qnode&r)const
	{
		return c>r.c;
	}
};
void Dijkstra(int n,int start)
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		dist[i]=inf;
	}
	priority_queue<qnode>q;
	while(!q.empty())
	{
		q.pop();
	}
	dist[start]=0;
	qnode start_node;
	start_node.v=start;
	start_node.c=0;
	q.push(start_node);
	qnode temp,new_node;
	int u,v,cost;
	while(!q.empty())
	{
		temp=q.top();
		q.pop();
		u=temp.v;
		if(vis[u])
		{
			continue;
		}
		vis[u]=true;
		int size=e[u].size();
		for(int i=0;i<size;++i)
		{
			v=e[u][i].v;
			cost=e[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost)
			{
				dist[v]=dist[u]+cost;
				new_node.v=v;
				new_node.c=dist[v];
				q.push(new_node);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v,w;
	Edge tmp;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		tmp.v=v;
		tmp.cost=w;
		e[u].push_back(tmp);
	}
	Dijkstra(n,1);
	printf("%d\n",dist[n]==inf?-1:dist[n]);
	return 0;
}
