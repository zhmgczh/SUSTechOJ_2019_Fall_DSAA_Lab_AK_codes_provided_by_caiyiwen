#include<cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long long cnt=0,base=1;
		while(cnt+base<n)
		{
			cnt+=base;
			base*=k;
		}
		long long nums=(n-cnt)/k;
		if((n-cnt)%k)
		{
			++nums;
		}
		printf("%lld\n",n-cnt+base/k-nums);
	}
	return 0;
}
