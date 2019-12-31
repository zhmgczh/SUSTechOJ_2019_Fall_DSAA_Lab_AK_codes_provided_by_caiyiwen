#include<cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		long long five=0;
		while(n)
		{
			n/=5;
			five+=n;
		}
		printf("%lld\n",five);
	}
	return 0;
}
