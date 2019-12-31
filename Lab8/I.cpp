#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int mod=(int)1e9+7;
vector<int>e[(int)1e5+10];
int ind[(int)1e5+10],order[(int)1e5+10],cnt,dp[(int)1e5+10],a[(int)1e5+10],b[(int)1e5+10];
void bfs(int n)
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
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			e[i].clear();
			dp[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		int u,v;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			++ind[v];
		}
		cnt=0;
		bfs(n);
		for(int i=0;i<cnt;++i)
		{
			int len=e[order[i]].size();
			for(int j=0;j<len;++j)
			{
				dp[e[order[i]][j]]=(dp[e[order[i]][j]]+(dp[order[i]]+a[order[i]%mod])%mod)%mod;
			}
		}
		int res=0;
		for(int i=1;i<=n;++i)
		{
			res=(res+(dp[i]*((long long)b[i]%mod))%mod)%mod;
		}
		printf("%d\n",res);
	}
	return 0;
}
