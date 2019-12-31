#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int>g[150010];
int value[150010];
bool in_deg[150010];
bool bfs(int root)
{
	queue<int>q;
	q.push(root);
	int cur=root;
	while(cur)
	{
		int u=q.front();
		q.pop();
		q.push(g[u][0]);
		q.push(g[u][1]);
		cur=q.front();
	}
	while(!q.empty())
	{
		if(q.front())
		{
			return false;
		}
		q.pop();
	}
	return true;
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
			in_deg[i]=false;
		}
		int x,y;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&x,&y);
			g[i].push_back(x);
			g[i].push_back(y);
			if(x)
			{
				in_deg[x]=true;
			}
			if(y)
			{
				in_deg[y]=true;
			}
		}
		int root;
		for(int i=1;i<=n;++i)
		{
			if(!in_deg[i])
			{
				root=i;
				break;
			}
		}
		printf("%s\n",bfs(root)?"Yes":"No");
	}
	return 0;
}
