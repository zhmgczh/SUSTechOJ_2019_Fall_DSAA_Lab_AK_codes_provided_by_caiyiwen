#include<cstdio>
using namespace std;
const int maxn=(int)2e5+10;
int coe[maxn],expo[maxn],Next[maxn],Prev[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,q,coef,expp,head=0,tot=1;
		Next[0]=Prev[0]=coe[0]=expo[0]=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&coef,&expp);
			if(expp==expo[head])
			{
				coe[head]+=coef;
			}
			else
			{
				coe[tot]=coef;
				expo[tot]=expp;
				Prev[Next[head]]=tot;
				Next[tot]=Next[head];
				Next[head]=tot;
				Prev[tot]=head;
				head=tot;
				tot++;
			}
		}
		scanf("%d",&m);
		head=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&coef,&expp);
			while(Next[head]!=0&&expo[Next[head]]<=expp)
			{
				head=Next[head];
			}
			if(expp==expo[head])
			{
				coe[head]+=coef;
			}
			else
			{
				coe[tot]=coef;
				expo[tot]=expp;
				Prev[Next[head]]=tot;
				Next[tot]=Next[head];
				Next[head]=tot;
				Prev[tot]=head;
				head=tot;
				tot++;
			}
		}
		scanf("%d",&q);
		head=0;
		while(q--)
		{
			scanf("%d",&expp);
			while(Next[head]!=0&&expo[Next[head]]<=expp)
			{
				head=Next[head];
			}
			if(expp==expo[head])
			{
				printf("%d ",coe[head]);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	return 0;
}
