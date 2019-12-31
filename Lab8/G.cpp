#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Edge
{
	int v,w;
	bool operator<(const Edge&b)const
	{
		return w<b.w;
	}
};
struct Road
{
	int s,last_t,t,ind;
	long long w;
	bool operator<(const Road&b)const
	{
		return w>b.w;
	}
};
vector<Edge>edge[(int)5e4+10];
int query[(int)5e4+10];
long long ans[(int)5e4+10];
priority_queue<Road>pq;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!pq.empty())
		{
			pq.pop();
		}
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i)
		{
			edge[i].clear();
		}
		Edge tmp_edge;
		for(int i=0;i<m;++i)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			tmp_edge.v=v;
			tmp_edge.w=w;
			edge[u].push_back(tmp_edge);
		}
		for(int i=1;i<=n;++i)
		{
			sort(edge[i].begin(),edge[i].end());
		}
		int max_query=0;
		for(int i=0;i<q;++i)
		{
			scanf("%d",&query[i]);
			max_query=max(query[i],max_query);
		}
		Road road_tmp;
		for(int i=1;i<=n;++i)
		{
			if(edge[i].size())
			{
				road_tmp.s=road_tmp.last_t=i;
				road_tmp.t=edge[i][0].v;
				road_tmp.ind=0;
				road_tmp.w=edge[i][0].w;
				pq.push(road_tmp);
			}
		}
		int current=1;
		int s,t,last_t,ind;
		long long w;
		Road next;
		while(current<=max_query)
		{
			ans[current]=pq.top().w;
			s=pq.top().s;
			t=pq.top().t;
			last_t=pq.top().last_t;
			ind=pq.top().ind;
			w=pq.top().w;
			if(ind<edge[last_t].size()-1)
			{
				next.s=s;
				next.last_t=last_t;
				next.ind=ind+1;
				next.t=edge[last_t][next.ind].v;
				next.w=w-edge[last_t][ind].w+edge[last_t][next.ind].w;
				pq.push(next);
			}
			if(edge[t].size())
			{
				next.s=s;
				next.last_t=t;
				next.ind=0;
				next.t=edge[t][next.ind].v;
				next.w=w+edge[t][next.ind].w;
				pq.push(next);
			}
			pq.pop();
			++current;
		}
		for(int i=0;i<q;++i)
		{
			printf("%lld\n",ans[query[i]]);
		}
	}
	return 0;
}
//http://www.voidcn.com/article/p-farrnokl-byy.html
