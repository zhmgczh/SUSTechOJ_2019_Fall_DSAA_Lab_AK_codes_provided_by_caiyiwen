#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=(int)2e5+10;
const int maxm=(int)2e5+10;
struct Edge
{
	int to,next;
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn];
int Index,top;
int scc;
bool Instack[maxn];
void addedge(int u,int v)
{
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void Tarjan(int u)
{
	int v;
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=true;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		v=edge[i].to;
		if(!DFN[v])
		{
			Tarjan(v);
			if(Low[u]>Low[v])
			{
				Low[u]=Low[v];
			}
		}
		else if(Instack[v]&&Low[u]>DFN[v])
		{
			Low[u]=DFN[v];
		}
	}
	if(Low[u]==DFN[u])
	{
		++scc;
		do
		{
			v=Stack[--top];
			Instack[v]=false;
		}
		while(v!=u);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;++i)
	{
		if(!DFN[i])
		{
			Tarjan(i);
		}
	}
	printf("%s\n",scc==1?"Bravo":"ovarB");
	return 0;
}
