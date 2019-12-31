#include<cstdio>
using namespace std;
int a[(int)1e6+10];
long long abso(long long num)
{
	return num<0?-num:num;
}
bool binary_search(int array[],int start,int n,int target)
{
	int low=start,high=n,middle=0;
	while(low<high)
	{
		middle=(low+high)>>1;
		if(target==array[middle])
		{
			return true;
		}
		else if(target<array[middle])
		{
			high=middle;
		}
		else if(target>array[middle])
		{
			low=middle+1;
		}
	}
	return false;
}
int main()
{
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==0)
	{
		bool have=false;
		int cnt=0,zero_cnt=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				zero_cnt++;
				have=true;
			}
			if(i>0&&a[i]==a[i-1])
			{
				continue;
			}
			if(a[i]!=0)
			{
				cnt++;
			}
		}
		if(have&&zero_cnt>1)
		{
			printf("%d\n",cnt+1);
		}
		else if(have)
		{
			printf("%d\n",cnt);
		}
		else
		{
			printf("0\n");
		}
	}
	else
	{
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			if(i>0&&a[i]==a[i-1])
			{
				continue;
			}
			if(a[i]!=0&&abso(m)%abso(a[i])==0)
			{
				bool have=binary_search(a,i+1,n,m/a[i]);
				if(have)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
