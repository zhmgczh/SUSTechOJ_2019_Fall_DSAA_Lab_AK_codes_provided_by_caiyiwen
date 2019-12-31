#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>=4)
	{
		printf("%lld\n",0);
	}
	else if(n==3)
	{
		long long res=1;
		for(int i=2;i<=720;i++)
		{
			res=res*i%m;
			if(!res)
			{
				break;
			}
		}
		printf("%lld\n",res);
	}
	else if(n==2)
	{
		printf("%lld\n",2%m);
	}
	else if(n<=1)
	{
		printf("%lld\n",1%m);
	}
	return 0;
}
