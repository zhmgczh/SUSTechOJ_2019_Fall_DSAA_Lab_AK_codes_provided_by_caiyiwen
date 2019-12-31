#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
vector<int>g[(int)1e5+10];
int value[(int)1e5+10];
bool is_bt,in_deg[(int)1e5+10];
int type;
int dfs(int u)
{
	if(!is_bt)
	{
		return 0;
	}
	int len=g[u].size();
	if(len>2)
	{
		is_bt=false;
		return 0;
	}
	int last_len,c_len=inf;
	for(int i=0;i<len;++i)
	{
		if(!is_bt)
		{
			return 0;
		}
		if(!type)
		{
			if(value[g[u][i]]>value[u])
			{
				type=1;
			}
			else if(value[g[u][i]]<value[u])
			{
				type=2;
			}
		}
		else if(type==1)
		{
			if(value[g[u][i]]<value[u])
			{
				is_bt=false;
				return 0;
			}
		}
		else
		{
			if(value[g[u][i]]>value[u])
			{
				is_bt=false;
				return 0;
			}
		}
	}
	return len;
}
bool bfs(int root)
{
	queue<int>q;
	q.push(root);
	int cur=root;
	while(cur)
	{
		int u=q.front();
		q.pop();
		int len=g[u].size();
		if(len==2)
		{
			q.push(g[u][0]);
			q.push(g[u][1]);
		}
		else if(len==1)
		{
			q.push(g[u][0]);
			q.push(0);
		}
		else
		{
			q.push(0);
			q.push(0);
		}
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
	int T,kcase=0;
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
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&value[i]);
		}
		int x,y;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			in_deg[y]=true;
		}
		is_bt=true;
		int root;
		for(int i=1;i<=n;++i)
		{
			if(!in_deg[i])
			{
				root=i;
				break;
			}
		}
		type=0;
		dfs(root);
		if(is_bt)
		{
			is_bt=bfs(root);
		}
		printf("Case #%d: %s\n",++kcase,is_bt?"YES":"NO");
	}
	return 0;
}
