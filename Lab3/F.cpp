#include<cstdio>
#include<cmath>
#define min(a,b) (a)>(b)?(b):(a)
using namespace std;
const int maxn=(int)2e6+10;
const int inf=0x3f3f3f3f;
int a[maxn],index[maxn],t[maxn],Next[maxn],Prev[maxn];
bool cmp(int x,int y)
{
	return a[x]<=a[y];
}
void sort(int b,int e)
{
	if(e-b<=0)
	{
		return;
	}
	int mid=(b+e)>>1,p1=b,p2=mid+1,i=b;
	sort(b,mid);
	sort(mid+1,e);
	while(p1<=mid||p2<=e)
	{
		if(p2>e||(p1<=mid&&cmp(index[p1],index[p2])))
		{
			t[i++]=index[p1++];
		}
		else
		{
			t[i++]=index[p2++];
		}
	}
	for(int i=b;i<=e;i++)
	{
		index[i]=t[i];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		index[i]=i;
	}
	sort(1,n);
	Next[0]=index[1];
	Prev[0]=index[n];
	Next[index[n]]=0;
	Prev[index[1]]=0;
	for(int i=1;i<=n-1;i++)
	{
		Next[index[i]]=index[i+1];
		Prev[index[i+1]]=index[i];
	}
	int head,value;
	for(int i=1;i<=n-1;i++)
	{
		head=i;
		value=inf;
		while(Next[head]!=0)
		{
			head=Next[head];
			if(head>i)
			{
				value=abs(a[head]-a[i]);
				break;
			}
		}
		head=i;
		while(Prev[head]!=0)
		{
			head=Prev[head];
			if(head>i)
			{
				value=min(value,abs(a[head]-a[i]));
				break;
			}
		}
		printf("%d ",value);
		Prev[Next[i]]=Prev[i];
		Next[Prev[i]]=Next[i];
	}
	return 0;
}
