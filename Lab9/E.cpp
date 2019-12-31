#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=(int)5e4+10;
const long long inf=0x3f3f3f3f3f3f3f3f;
struct Edge
{
	int v,cost;
};
vector<Edge>e[maxn];
vector<int>por[maxn];
bool vis[11][maxn];
long long dist[11][maxn];
struct qnode
{
	int v,past;
	long long c;
	bool operator<(const qnode&r)const
	{
		return c>r.c;
	}
};
inline void Dijkstra(int n,int start,int k)
{
	for(int i=0;i<=k;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dist[i][j]=inf;
		}
	}
	priority_queue<qnode>q;
	dist[0][start]=0;
	qnode start_node;
	start_node.v=start;
	start_node.c=0;
	start_node.past=0;
	q.push(start_node);
	qnode temp,new_node;
	int u,v,cost;
	while(!q.empty())
	{
		temp=q.top();
		q.pop();
		u=temp.v;
		if(vis[temp.past][u])
		{
			continue;
		}
		vis[temp.past][u]=true;
		new_node.past=temp.past;
		int size=e[u].size();
		for(int i=0;i<size;++i)
		{
			v=e[u][i].v;
			cost=e[u][i].cost;
			if(!vis[new_node.past][v]&&dist[new_node.past][v]>dist[temp.past][u]+cost)
			{
				dist[new_node.past][v]=dist[temp.past][u]+cost;
				new_node.v=v;
				new_node.c=dist[new_node.past][v];
				q.push(new_node);
			}
		}
		if(temp.past<k)
		{
			new_node.past=temp.past+1;
			int len=por[u].size();
			for(int i=0;i<len;++i)
			{
				v=por[u][i];
				if(!vis[new_node.past][v]&&dist[new_node.past][v]>dist[temp.past][u])
				{
					dist[new_node.past][v]=dist[temp.past][u];
					new_node.v=v;
					new_node.c=dist[new_node.past][v];
					q.push(new_node);
				}
			}
		}
	}
}
int main()
{
	int n,m,p,k;
	scanf("%d%d%d%d",&n,&m,&p,&k);
	int u,v,w;
	Edge tmp;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		tmp.cost=w;
		tmp.v=v;
		e[u].push_back(tmp);
	}
	for(int i=0;i<p;++i)
	{
		scanf("%d%d",&u,&v);
		por[u].push_back(v);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	Dijkstra(n,s,k);
	long long ans=inf;
	for(int i=0;i<=k;++i)
	{
		ans=min(ans,dist[i][t]);
	}
	printf("%lld\n",ans);
	return 0;
}
