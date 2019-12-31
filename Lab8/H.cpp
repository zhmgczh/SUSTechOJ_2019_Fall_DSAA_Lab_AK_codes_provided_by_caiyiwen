#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
bool e[510][510];
int ind[510],entry[(int)1e5+10][2],ind_backup[510];
void bfs(int n,bool(*e)[510])
{
	queue<int>q;
	for(int i=1;i<=n;++i)
	{
		if(!ind[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;++i)
		{
			if(e[u][i])
			{
				e[u][i]=false;
				--ind[i];
				if(!ind[i])
				{
					q.push(i);
				}
			}
		}
	}
}
int deleted;
void fast_bfs(int start,int n,bool(*e)[510])
{
	queue<int>q;
	q.push(start);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;++i)
		{
			if(e[u][i])
			{
				++deleted;
				e[u][i]=false;
				--ind[i];
				if(!ind[i])
				{
					q.push(i);
				}
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
			ind[i]=0;
			for(int j=1;j<=n;++j)
			{
				e[i][j]=false;
			}
		}
		int u,v;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			e[u][v]=true;
			++ind[v];
		}
		bfs(n,e);
		bool ok=true;
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			ind_backup[i]=ind[i];
			for(int j=1;j<=n;++j)
			{
				if(e[i][j])
				{
					entry[cnt][0]=i;
					entry[cnt++][1]=j;
					ok=false;
				}
			}
		}
		int pos=0;
		while(!ok&&pos<cnt)
		{
			e[entry[pos][0]][entry[pos][1]]=false;
			--ind[entry[pos][1]];
			if(!ind[entry[pos][1]])
			{
				deleted=1;
				fast_bfs(entry[pos][1],n,e);
				if(deleted==cnt)
				{
					ok=true;
					break;
				}
				for(int i=1;i<=n;++i)
				{
					ind[i]=ind_backup[i];
				}
				for(int i=0;i<cnt;++i)
				{
					e[entry[i][0]][entry[i][1]]=true;
				}
			}
			e[entry[pos][0]][entry[pos][1]]=true;
			ind[entry[pos][1]]=ind_backup[entry[pos][1]];
			++pos;
		}
		if(ok)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
