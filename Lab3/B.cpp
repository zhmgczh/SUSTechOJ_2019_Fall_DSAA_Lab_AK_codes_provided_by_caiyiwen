#include<cstdio>
using namespace std;
const int maxn=(int)1e5+10;
int Next[maxn],Prev[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Next[0]=Prev[0]=0;
		int n,m,tmp,last=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			tmp++;
			Next[tmp]=Next[last];
			Prev[Next[last]]=tmp;
			Next[last]=tmp;
			Prev[tmp]=last;
			last=tmp;
		}
		int x1,y1,x2,y2;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1++;
			y1++;
			x2++;
			y2++;
			int a1=Prev[x1],a2=Next[y1],a3=Prev[x2],a4=Next[y2];
			if(Next[y1]!=x2&&Next[y2]!=x1)
			{
				Next[a1]=x2;
				Prev[x2]=a1;
				Next[y2]=a2;
				Prev[a2]=y2;
				Next[a3]=x1;
				Prev[x1]=a3;
				Prev[a4]=y1;
				Next[y1]=a4;
			}
			else if(Next[y1]==x2)
			{
				Next[a1]=x2;
				Prev[x2]=a1;
				Next[y2]=x1;
				Prev[x1]=y2;
				Next[y1]=a4;
				Prev[a4]=y1;
			}
			else
			{
				Next[a3]=x1;
				Prev[x1]=a3;
				Next[y1]=x2;
				Prev[x2]=y1;
				Next[y2]=a2;
				Prev[a2]=y2;
			}
		}
		tmp=0;
		for(int i=0;i<n;i++)
		{
			tmp=Next[tmp];
			printf("%d ",tmp-1);
		}
		printf("\n");
	}
	return 0;
}
