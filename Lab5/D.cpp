#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
using namespace std;
char p[(int)1e5+10];
int next[(int)1e5+10];
void CalcNext(int pLen)
{
	next[0]=-1;
	int k=-1,j=0;
	while(j<pLen)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
		{
			k=next[k];
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",p);
		int len=strlen(p);
		CalcNext(len);
		int L=len-next[len],res;
		if(L<len)
		{
			if(len%L)
			{
				res=L-len%L;
			}
			else
			{
				res=0;
			}
		}
		else
		{
			res=len;
		}
		printf("%d\n",res);
	}
	return 0;
}
