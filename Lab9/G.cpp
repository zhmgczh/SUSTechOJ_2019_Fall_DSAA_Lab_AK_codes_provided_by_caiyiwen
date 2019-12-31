#pragma GCC optimize(2)
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=(int)1e5+10;
vector<int>e[maxn],back_e[maxn],new_e[100];
int ind[maxn],outd[maxn],n,m,Next[maxn],Prev[maxn],Start[30],End[30],color[maxn];
struct node
{
	int s,t;
}entry[100];
bool vis[100],ok;
int entry_cnt,ans[maxn],tot,res[maxn];
void dfs(int u)
{
	vis[u]=true;
	ans[tot++]=u;
	int len=new_e[u].size();
	for(int i=0;i<len&&!ok;++i)
	{
		if(vis[new_e[u][i]])
		{
			if(tot==entry_cnt&&new_e[u][i]==1)
			{
				ok=true;
				return;
			}
		}
		else
		{
			dfs(new_e[u][i]);
		}
	}
	if(ok)
	{
		return;
	}
	--tot;
	vis[u]=false;
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&u,&v);
		if(u==v)
		{
			continue;
		}
		e[u].push_back(v);
		back_e[v].push_back(u);
		++ind[v];
		++outd[u];
	}
	if(m<n)
	{
		printf("ovarB");
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;++i)
		{
			if(ind[i]!=1||outd[i]!=1)
			{
				printf("ovarB");
				return 0;
			}
		}
		printf("1 ");
		int pos=e[1][0];
		while(pos!=1)
		{
			printf("%d ",pos);
			pos=e[pos][0];
		}
		putchar('1');
	}
	else
	{
		int s_cnt=0,e_cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(!ind[i])
			{
				printf("ovarB");
				return 0;
			}
			if(!outd[i])
			{
				printf("ovarB");
				return 0;
			}
			if(ind[i]==1)
			{
				if(Next[back_e[i][0]]!=i&&Next[back_e[i][0]])
				{
					printf("ovarB");
					return 0;
				}
				Next[back_e[i][0]]=i;
				Prev[i]=back_e[i][0];
			}
			else
			{
				End[e_cnt++]=i;
			}
			if(outd[i]==1)
			{
				if(Prev[e[i][0]]!=i&&Prev[e[i][0]])
				{
					printf("ovarB");
					return 0;
				}
				Next[i]=e[i][0];
				Prev[e[i][0]]=i;
			}
			else
			{
				Start[s_cnt++]=i;
			}
		}
		entry_cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(!Prev[i])
			{
				entry[entry_cnt+1].s=i;
				int pos=i;
				while(Next[pos])
				{
					color[pos]=entry_cnt+1;
					pos=Next[pos];
				}
				color[pos]=entry_cnt+1;
				entry[entry_cnt+1].t=pos;
				++entry_cnt;
			}
		}
		if(entry_cnt==0)
		{
			int pos=1;
			while(Next[pos]!=1)
			{
				printf("%d ",pos);
				pos=Next[pos];
			}
			printf("%d ",pos);
			putchar('1');
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				if(!color[i])
				{
					printf("ovarB");
					return 0;
				}
			}
			for(int i=1;i<=entry_cnt;++i)
			{
				int len=e[entry[i].t].size();
				for(int j=0;j<len;++j)
				{
					if(e[entry[i].t][j]==entry[color[e[entry[i].t][j]]].s)
					{
						new_e[i].push_back(color[e[entry[i].t][j]]);
					}
				}
			}
			dfs(1);
			if(ok)
			{
				int cnt=0;
				for(int i=0;i<tot;++i)
				{
					int pos=entry[ans[i]].s;
					while(Next[pos])
					{
						res[cnt++]=pos;
						pos=Next[pos];
					}
					res[cnt++]=pos;
				}
				int one=0;
				for(int i=0;i<cnt;++i)
				{
					if(res[i]==1)
					{
						one=i;
						break;
					}
				}
				printf("1 ");
				for(int i=(one+1)%cnt;i!=one;i=(i+1)%cnt)
				{
					printf("%d ",res[i]);
				}
				putchar('1');
			}
			else
			{
				printf("ovarB");
			}
		}
	}
	return 0;
}
