#include<cstdio>
#include<algorithm>
using namespace std;
const char order[10]={'W','T','Y','E','S','W','N','B','F','Z'};
char s[13][3];
int index[13];
bool cmp(int a,int b)
{
	if(s[a][0]==s[b][0]&&s[a][1]!='\0'&&s[b][1]!='\0')
	{
		return s[a][1]<s[b][1];
	}
	int a_p,b_p;
	for(int i=0;i<10;i++)
	{
		if(s[a][0]==order[i])
		{
			a_p=i;
		}
		if(s[b][0]==order[i])
		{
			b_p=i;
		}
	}
	if(s[a][1]!='\0')
	{
		for(int i=0;i<3;i++)
		{
			if(s[a][0]==order[i])
			{
				a_p=i;
			}
		}
	}
	if(s[b][1]!='\0')
	{
		for(int i=0;i<3;i++)
		{
			if(s[b][0]==order[i])
			{
				b_p=i;
			}
		}
	}
	return a_p<b_p;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<13;i++)
		{
			scanf("%s",s[i]);
			index[i]=i;
		}
		sort(index,index+13,cmp);
		for(int i=0;i<12;i++)
		{
			printf("%s ",s[index[i]]);
		}
		printf("%s\n",s[index[12]]);
	}
	return 0;
}
