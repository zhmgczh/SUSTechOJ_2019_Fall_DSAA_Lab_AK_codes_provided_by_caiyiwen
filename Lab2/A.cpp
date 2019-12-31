#include<cstdio>
#include<cstring>
using namespace std;
int a[101],have[101];
void quicksort(int b,int e,int a[])
{
	int i=b,j=e,x=a[(b+e)>>1];
	do
	{
		while(a[i]<x)
		{
			i++;
		}
		while(a[j]>x)
		{
			j--;
		}
		if(i<=j)
		{
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	}
	while(i<j);
	if(i<e)
	{
		quicksort(i,e,a);
	}
	if(j>b)
	{
		quicksort(b,j,a);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(have,0,sizeof(have));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			have[a[i]]++;
		}
		quicksort(0,n-1,a);
		if(have[a[n-3]]>1)
		{
			printf("wa\n");
		}
		else
		{
			printf("%d\n",a[n-3]);
		}
	}
	return 0;
}
