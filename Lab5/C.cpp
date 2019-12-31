#pragma GCC optimize(2)
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char s[10010],p[10010];
int next[10010];
void CalcNext(int pLen,char*p,int*next)
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
int KMP(int tLen,int pLen,char*t,char*p,int*next)
{
	int ans=-1;
	int i=0,j=0;
	while(i<tLen)
	{
		if(j==-1||t[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
		if(j==pLen)
		{
			ans=i-pLen;
			break;
		}
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int res=0;
	while(n--)
	{
		scanf("%s%s",s,p);
		int lens=strlen(s);
		int lenp=strlen(p);
		int plen;
		if(lens%3)
		{
			plen=lens/3+1;
		}
		else
		{
			plen=lens/3;
		}
		CalcNext(plen,s,next);
		if(KMP(lenp,plen,p,s,next)!=-1)
		{
			res++;
		}
	}
	printf("%d\n",res);
	return 0;
}
