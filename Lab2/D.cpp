#include<cstdio>
using namespace std;
const int inf=0x3f3f3f3f;
int a[(int)1e5+10],L[(int)1e5+10],R[(int)1e5+10];
long long ans,last_sum[(int)1e5+10];
void merge(int p,int q,int r)
{
	int n1=q-p+1,n2=r-q;
	last_sum[n1+1]=0;
	for(int i=n1;i>=1;i--)
	{
		L[i]=a[p+i-1];
		last_sum[i]=last_sum[i+1]+L[i];
	}
	for(int i=1;i<=n2;i++)
	{
		R[i]=a[q+i];
	}
	L[n1+1]=R[n2+1]=inf;
	int i=1,j=1;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i++];
		}
		else
		{
			a[k]=R[j++];
			ans+=(q-i-p+2)*(long long)a[k]+last_sum[n1-(q-i-p+1)];
		}
	}
}
void merge_sort(int p,int r)
{
	if(p<r)
	{
		int q=(p+r)>>1;
		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	ans=0;
	merge_sort(1,n);
	printf("%lld\n",ans);
	return 0;
}
