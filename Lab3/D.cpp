#include<cstdio>
using namespace std;
const int maxn=(int)1e4+10;
int Next[maxn],Prev[maxn],w[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++)
		{
			Next[i]=i+1;
			Prev[i+1]=i;
			scanf("%d",&w[i]);
		}
		Next[n]=1;
		Prev[1]=n;
		scanf("%d",&w[n]);
		int head=1,num=n;
		while(num>1)
		{
			m--;
			m%=num;
			if(m>num-m)
			{
				m=num-m;
				for(int i=0;i<m;i++)
				{
					head=Prev[head];
				}
			}
			else
			{
				for(int i=0;i<m;i++)
				{
					head=Next[head];
				}
			}
			m=w[head];
			Prev[Next[head]]=Prev[head];
			Next[Prev[head]]=Next[head];
			head=Next[head];
			num--;
		}
		printf("%d\n",head);
	}
	return 0;
}
