#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int maxm=10010;
int F[maxn];
struct Edge
{
	int u,v,w;
}edge[maxm];
int tol;
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	return F[x]==-1?x:(F[x]=find(F[x]));
}
long long Kruskal(int n)
{
	memset(F,-1,sizeof(F));
	sort(edge,edge+tol,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=0;i<tol;++i)
	{
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		int t1=find(u);
		int t2=find(v);
		if(t1!=t2)
		{
			ans+=w;
			F[t1]=t2;
			++cnt;
		}
		if(cnt==n-1)
		{
			break;
		}
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		edge[tol].u=u;
		edge[tol].v=v;
		edge[tol++].w=w;
	}
	printf("%lld\n",Kruskal(n));
	return 0;
}
