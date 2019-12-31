#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=(int)2e5+10;
vector<int>e[maxn];
int vis[maxn];
struct status
{
	int u,need;
};
void bfs(int s)
{
	queue<status>q;
	vis[s]=1;
	status start;
	start.u=s;
	start.need=1;
	q.push(start);
	status current,next;
	while(!q.empty())
	{
		current=q.front();
		q.pop();
		int len=e[current.u].size();
		next.need=-current.need;
		for(int i=0;i<len;++i)
		{
			if(!vis[e[current.u][i]])
			{
				next.u=e[current.u][i];
				vis[next.u]=next.need;
				q.push(next);
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			vis[i]=0;
			e[i].clear();
		}
		int u,v;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int start=0;
		for(int i=1;i<=n;++i)
		{
			if(e[i].size()>e[start].size())
			{
				start=i;
			}
		}
		bfs(start);
		int o_cnt=0,e_cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]==1)
			{
				++o_cnt;
			}
			else
			{
				++e_cnt;
			}
		}
		if(o_cnt<=e_cnt)
		{
			printf("%d\n",o_cnt);
			for(int i=1;i<=n;++i)
			{
				if(vis[i]==1)
				{
					printf("%d ",i);
				}
			}
		}
		else
		{
			printf("%d\n",e_cnt);
			for(int i=1;i<=n;++i)
			{
				if(vis[i]==-1)
				{
					printf("%d ",i);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
