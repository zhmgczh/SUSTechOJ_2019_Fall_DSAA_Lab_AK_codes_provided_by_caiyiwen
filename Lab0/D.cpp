#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int digit[11],num[11];
long long get_s_com(long long cnum)
{
	int cdig_num=0;
	while(cnum)
	{
		num[cdig_num]=cnum%10;
		cnum/=10;
		cdig_num++;
	}
	long long res=0;
	for(int i=0;i<cdig_num-1;i++)
	{
		res=res*10+num[cdig_num-i-1];
	}
	res=res*10+num[0];
	for(int i=cdig_num-2;i>=0;i--)
	{
		res=res*10+num[cdig_num-i-1];
	}
	return res;
}
long long get_e_com(long long cnum)
{
	int cdig_num=0;
	while(cnum)
	{
		num[cdig_num]=cnum%10;
		cnum/=10;
		cdig_num++;
	}
	long long res=0;
	for(int i=0;i<cdig_num;i++)
	{
		res=res*10+num[cdig_num-i-1];
	}
	for(int i=cdig_num-1;i>=0;i--)
	{
		res=res*10+num[cdig_num-i-1];
	}
	return res;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		if(n<10)
		{
			printf("%lld\n",n+1);
		}
		else
		{
			long long ans=0;
			long long tmp=n;
			int dig_num=0;
			while(tmp)
			{
				digit[dig_num]=tmp%10;
				tmp/=10;
				dig_num++;
			}
			int idig_num=dig_num&1?(dig_num+1)>>1:dig_num>>1;
			long long upper=(long long)pow(10,idig_num)-1;
			for(int i=0;i<=upper;i++)
			{
				long long s=get_s_com(i),e=get_e_com(i);
				if(s<=n)
				{
					ans++;
				}
				if(e<=n)
				{
					ans++;
				}
			}
			printf("%lld\n",ans-1);
		}
	}
	return 0;
}
