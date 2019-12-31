#include<cstdio>
#include<algorithm>
using namespace std;
long long a[3001];
void quicksort(int b,int e,long long a[])
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
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	quicksort(0,n-1,a);
	long long res=0;
	for(int i=0;i<n-2;i++)
	{
		int l=i+1,r=n-1;
		while(l<r)
		{
			long long sum=a[i]+a[l]+a[r];
			if(sum<m)
			{
				l++;
			}
			else if(sum>m)
			{
				r--;
			}
			else
			{
				if(a[l]!=a[r])
				{
					int cl=l,cr=r;
					while(cl<n-1&&a[cl+1]==a[l])
					{
						cl++;
					}
					while(cr>i+1&&a[cr-1]==a[r])
					{
						cr--;
					}
					res+=(cl-l+1)*(r-cr+1);
					l=cl+1;
					r=cr-1;
				}
				else
				{
					int cl=l;
					while(cl<n-1&&a[cl+1]==a[l])
					{
						cl++;
					}
					res+=(cl-l+1)*(long long)(cl-l)/2;
					break;
				}
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}
