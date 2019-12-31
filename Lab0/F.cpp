#include<cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int k=-1;
		for(int i=2;(long long)i*(i-1)>>1<n;i++)
		{
			if((n-(i*(i-1)>>1))%i==0)
			{
				int tmp=(n-(i*(i-1)>>1))/i;
				if(tmp>=1)
				{
					k=i;
					break;
				}
			}
		}
		if(k==-1)
		{
			printf("impossible\n");
		}
		else
		{
			printf("%d\n",k);
		}
	}
	return 0;
}
