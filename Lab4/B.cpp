#include<cstdio>
using namespace std;
char sta[(int)3e4+10],s[(int)3e4+10];
int top;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		top=-1;
		scanf("%s",s);
		bool ok=true;
		for(int i=0;i<n;i++)
		{
			if(s[i]==')')
			{
				if(top==-1||sta[top]!='(')
				{
					ok=false;
					break;
				}
				top--;
			}
			else if(s[i]==']')
			{
				if(top==-1||sta[top]!='[')
				{
					ok=false;
					break;
				}
				top--;
			}
			else if(s[i]=='}')
			{
				if(top==-1||sta[top]!='{')
				{
					ok=false;
					break;
				}
				top--;
			}
			else
			{
				sta[++top]=s[i];
			}
		}
		if(top!=-1)
		{
			ok=false;
		}
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}
