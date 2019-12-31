#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
vector<int>e[(int)4e5+10];
int order[(int)2e5+10],ind[(int)2e5+10],cnt,n,m;
void bfs()
{
	priority_queue<int,vector<int>,less<int> >q;
	for(int i=1;i<=n;++i)
	{
		if(!ind[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		order[cnt++]=u;
		int len=e[u].size();
		for(int i=0;i<len;++i)
		{
			--ind[e[u][i]];
			if(!ind[e[u][i]])
			{
				q.push(e[u][i]);
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
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			ind[i]=0;
			e[i].clear();
		}
		int u,v;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			e[v].push_back(u);
			++ind[u];
		}
		cnt=0;
		bfs();
		for(int i=cnt-1;i>=0;--i)
		{
			printf("%d ",order[i]);
		}
		putchar('\n');
	}
	return 0;
}
