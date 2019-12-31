#include<cstdio>
using namespace std;
int a[(int)1e6+1];
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
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1,a);
	printf("%d\n",a[k-1]);
	return 0;
}
