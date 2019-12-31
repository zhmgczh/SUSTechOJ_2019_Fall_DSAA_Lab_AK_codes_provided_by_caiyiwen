#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[2010];
int cnt;
struct node
{
	int a,b,h;
}entry[2010];
bool cmp(node a,node b)
{
	if(a.a==b.a)
	{
		if(a.b==b.b)
		{
			return a.h>b.h;
		}
		return a.b>b.b;
	}
	return a.a>b.a;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	int n;
    	scanf("%d",&n);
    	cnt=0;
    	while(n--)
    	{
    		int a,b,c;
    		scanf("%d%d%d",&a,&b,&c);
    		entry[cnt].a=min(a,b);
    		entry[cnt].b=max(a,b);
    		entry[cnt++].h=c;
		}
		sort(entry,entry+cnt,cmp);
    	for(int i=0;i<cnt;++i)
    	{
    		d[i]=entry[i].h;
			for(int j=0;j<i;j++)
			{
				if(entry[j].a>entry[i].a&&entry[j].b>entry[i].b)
				{
					d[i]=max(d[i],d[j]+entry[i].h);
				}
			}
		}
		int maxi=0;
		for(int i=0;i<cnt;++i)
		{
			if(d[i]>maxi)
			{
				maxi=d[i];
			}
		}
		printf("%d\n",maxi);
	}
    return 0;
}
