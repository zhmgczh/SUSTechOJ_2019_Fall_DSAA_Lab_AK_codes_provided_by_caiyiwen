#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
using namespace std;
char s[(int)1e6+10];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int len=strlen(s);
		printf("%lld\n",(len+1)*(long long)len/2);
	}
	return 0;
}
