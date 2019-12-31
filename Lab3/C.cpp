#include<cstdio>
using namespace std;
const int maxn=(int)2e5+10;
char order[maxn],w[maxn];
int Next[maxn],Prev[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Next[0]=Prev[0]=0;
		int n,pointer=0,tot=1;
		bool mode=false;
		scanf("%d%s",&n,order);
		for(int i=0;i<n;i++)
		{
			if(order[i]=='r')
			{
				mode=true;
			}
			else if(order[i]=='I')
			{
				pointer=Next[0];
			}
			else if(order[i]=='H')
			{
				if(Prev[pointer]!=0)
				{
					pointer=Prev[pointer];
				}
			}
			else if(order[i]=='L')
			{
				if(pointer!=0)
				{
					pointer=Next[pointer];
				}
			}
			else if(order[i]=='x')
			{
				if(pointer!=0)
				{
					int tmp=Next[pointer];
					Prev[Next[pointer]]=Prev[pointer];
					Next[Prev[pointer]]=Next[pointer];
					pointer=tmp;
				}
			}
			else
			{
				if(mode)
				{
					mode=false;
					if(pointer==0)
					{
						w[tot]=order[i];
						Next[Prev[pointer]]=tot;
						Prev[tot]=Prev[pointer];
						Next[tot]=pointer;
						Prev[pointer]=tot;
						tot++;
						pointer=Prev[pointer];
					}
					else
					{
						w[pointer]=order[i];
					}
				}
				else
				{
					w[tot]=order[i];
					Next[Prev[pointer]]=tot;
					Prev[tot]=Prev[pointer];
					Next[tot]=pointer;
					Prev[pointer]=tot;
					tot++;
				}
			}
		}
		int tmp=Next[0];
		while(tmp!=0)
		{
			printf("%c",w[tmp]);
			tmp=Next[tmp];
		}
		printf("\n");
	}
	return 0;
}
