#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=(int)5e4+10;
int F[maxn];
struct Edge
{
	int u,v,w;
}edge[(int)6e5+10];
int tol;
bool cmp(Edge a,Edge b)
{
	return a.w>b.w;
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
	int c[n][m];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			scanf("%d",&c[i][j]);
			if(i>0)
			{
				edge[tol].u=i*m+j+1;
				edge[tol].v=(i-1)*m+j+1;
				edge[tol++].w=c[i][j]*c[i-1][j];
			}
			if(j>0)
			{
				edge[tol].u=i*m+j+1;
				edge[tol].v=i*m+j;
				edge[tol++].w=c[i][j]*c[i][j-1];
			}
		}
	}
	printf("%lld\n",Kruskal(m*n));
	return 0;
}
