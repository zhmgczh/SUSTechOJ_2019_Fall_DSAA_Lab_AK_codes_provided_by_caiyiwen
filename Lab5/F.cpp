#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
using namespace std;
char c_to_n[26],n_to_c[26],tmp[2],s[(int)1e5+10],p[(int)2e5+10],test[(int)2e5+10];
int next[(int)2e5+10];
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
int main()
{
	for(int i=0;i<26;i++)
	{
		scanf("%s",tmp);
		n_to_c[i]=tmp[0];
		c_to_n[tmp[0]-'a']=i+'a';
	}
	scanf("%s",s);
	int lens=strlen(s);
	for(int i=0;i<lens;i++)
	{
		p[i]=s[i];
	}
	for(int i=0;i<lens;i++)
	{
		p[i+lens]=n_to_c[s[i]-'a'];
	}
	CalcNext(lens<<1,p,next);
	int pos=lens<<1;
	while(pos>lens)
	{
		pos=next[pos];
	}
	int res=lens;
	while(pos>0)
	{
		int pre_len=lens-pos;
		int su_len=lens-pre_len;
		if(pre_len>=su_len&&su_len>0)
		{
			for(int i=0;i<su_len;i++)
			{
				test[i]=p[i+pre_len];
			}
			bool ok=true;
			for(int i=0;i<su_len;i++)
			{
				if(test[i]!=c_to_n[p[i]-'a'])
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				res=pre_len;
				break;
			}
		}
		pos=next[pos];
	}
	printf("%d\n",res);
	return 0;
}
