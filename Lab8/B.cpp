#include<cstdio>
#include<cstring>
using namespace std;
int entry[1010][3];
struct Edge
{
	int u,v,next;
}edge[(int)2e6+10];
int head[(int)1e3+10],tot;
int m,n,k;
void addedge(int u,int v)
{
	edge[tot].u=u;
	edge[tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
bool toke[(int)1e3+10],ans;
void dfs(int u)
{
	toke[u]=true;
	if(entry[u][1]<=entry[u][2]||m-entry[u][0]<=entry[u][2])
	{
		ans=true;
		return;
	}
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!toke[v])
		{
			dfs(v);
		}
		if(ans)
		{
			return;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(head,-1,sizeof(head));
		tot=0;
		ans=false;
		scanf("%d%d%d",&m,&n,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&entry[i][0],&entry[i][1],&entry[i][2]);
			for(int j=0;j<i;j++)
			{
				if((entry[i][0]-entry[j][0])*(entry[i][0]-entry[j][0])+(entry[i][1]-entry[j][1])*(entry[i][1]-entry[j][1])<=(entry[i][2]+entry[j][2])*(entry[i][2]+entry[j][2]))
				{
					addedge(i,j);
					addedge(j,i);
				}
			}
		}
		for(int i=0;i<k;i++)
		{
			if(entry[i][0]<=entry[i][2]||n-entry[i][1]<=entry[i][2])
			{
				memset(toke,false,sizeof(toke));
				dfs(i);
				if(ans)
				{
					break;
				}
			}
		}
		if(ans)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}
