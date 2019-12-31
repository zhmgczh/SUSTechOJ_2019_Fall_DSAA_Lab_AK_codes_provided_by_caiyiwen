#include<cstdio>
#include<cmath>
#define max(a,b) (a)<(b)?(b):(a)
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int digits;
		long long num;
		scanf("%d%lld",&digits,&num);
		long long maxi=(long long)pow((long long)10,digits)-1;
		long long tmp=num,res=num,fast=num*num;
		while(fast>maxi)
		{
			fast/=10;
		}
		while(tmp!=fast)
		{
			tmp=tmp*tmp;
			while(tmp>maxi)
			{
				tmp/=10;
			}
			fast=fast*fast;
			while(fast>maxi)
			{
				fast/=10;
			}
			res=max(res,fast);
			fast=fast*fast;
			while(fast>maxi)
			{
				fast/=10;
			}
			res=max(res,tmp);
			res=max(res,fast);
		}
		printf("%lld\n",res);
	}
}
