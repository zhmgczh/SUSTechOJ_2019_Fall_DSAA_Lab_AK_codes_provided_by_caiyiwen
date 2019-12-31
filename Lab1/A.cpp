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
		printf("%lld\n",n*(n+1)*(n+2)/6);
	}
	return 0;
}
