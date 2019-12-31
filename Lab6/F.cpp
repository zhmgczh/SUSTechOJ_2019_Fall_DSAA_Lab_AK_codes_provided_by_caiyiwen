#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>g[(int)1e5+10];
bool is_per[(int)1e5+10];
int far_len,far_ind;
void dfs(int u,int far,int dep)
{
	if(is_per[u]&&far_len<dep)
	{
		far_len=dep;
		far_ind=u;
	}
	int len=g[u].size();
	for(int i=0;i<len;++i)
	{
		if(g[u][i]!=far)
		{
			dfs(g[u][i],u,dep+1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(is_per,false,sizeof(is_per));
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
		{
			g[i].clear();
		}
		int u,v;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=0;i<k;++i)
		{
			scanf("%d",&u);
			is_per[u]=true;
		}
		if(k==1)
		{
			printf("0\n");
		}
		else
		{
			far_len=0;
			dfs(1,-1,0);
			far_len=0;
			dfs(far_ind,-1,0);
			if(far_len&1)
			{
				far_len=(far_len>>1)+1;
			}
			else
			{
				far_len>>=1;
			}
			printf("%d\n",far_len);
		}
	}
	return 0;
}
