#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
char s[80];
stack<int>num;
struct node
{
	int type;
	int num;
	char op;
}entry[80],post[80],opr[80];
int top;
bool is_dig(char bb)
{
	if(bb>='0'&&bb<='9')
	{
		return true;
	}
	return false;
}
bool is_op(char bb)
{
	if(bb=='+'||bb=='-'||bb=='*'||bb=='&'||bb=='~'||bb=='|'||bb=='^')
	{
		return true;
	}
	return false;
}
int priority(char bb)
{
	if(bb=='&')
	{
		return 0;
	}
	if(bb=='^')
	{
		return -1;
	}
	if(bb=='|')
	{
		return -2;
	}
	if(bb=='+'||bb=='-')
	{
		return 1;
	}
	if(bb=='*')
	{
		return 2;
	}
}
int one_p(int a,char op)
{
	if(op=='+')
	{
		return a;
	}
	if(op=='-')
	{
		return -a;
	}
	if(op=='~')
	{
		return ~a;
	}
}
int process(int a,int b,char op)
{
	if(op=='+')
	{
		return a+b;
	}
	if(op=='-')
	{
		return b-a;
	}
	if(op=='*')
	{
		return a*b;
	}
	if(op=='&')
	{
		return a&b;
	}
	if(op=='|')
	{
		return a|b;
	}
	return b^a;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		top=-1;
		while(!num.empty())
		{
			num.pop();
		}
		scanf("%s",s);
		int len=strlen(s);
		int cnt=0;
		for(int i=0;i<len;i++)
		{
			if(is_dig(s[i]))
			{
				entry[cnt].type=1;
				entry[cnt].num=s[i]-'0';
				cnt++;
			}
			else if(is_op(s[i]))
			{
				if(i>0&&(is_dig(s[i-1])||s[i-1]==')'))
				{
					entry[cnt].type=2;
					entry[cnt].op=s[i];
					cnt++;
				}
				else
				{
					entry[cnt].type=3;
					entry[cnt].op=s[i];
					cnt++;
				}
			}
			else
			{
				entry[cnt].type=2;
				entry[cnt].op=s[i];
				cnt++;
			}
		}
		int p_cnt=0;
		for(int i=0;i<cnt;i++)
		{
			if(entry[i].type==2)
			{
				if(entry[i].op=='(')
				{
					opr[++top]=entry[i];
				}
				else if(entry[i].op==')')
				{
					while(top!=-1&&opr[top].op!='(')
					{
						post[p_cnt++]=opr[top];
						top--;
					}
					top--;
				}
				else if(top==-1||opr[top].op=='('||priority(entry[i].op)>priority(opr[top].op))
				{
					opr[++top]=entry[i];
				}
				else
				{
					while(top!=-1&&opr[top].op!='('&&priority(entry[i].op)<=priority(opr[top].op))
					{
						post[p_cnt++]=opr[top];
						top--;
					}
					opr[++top]=entry[i];
				}
			}
			else if(entry[i].type==1)
			{
				post[p_cnt++]=entry[i];
			}
			else
			{
				opr[++top]=entry[i];
			}
		}
		while(top!=-1)
		{
			post[p_cnt++]=opr[top];
			top--;
		}
		int a,b;
		for(int i=0;i<p_cnt;i++)
		{
			if(post[i].type==3)
			{
				a=num.top();
				num.pop();
				num.push(one_p(a,post[i].op));
			}
			else if(post[i].type==2)
			{
				a=num.top();
				num.pop();
				b=num.top();
				num.pop();
				num.push(process(a,b,post[i].op));
			}
			else if(post[i].type==1)
			{
				num.push(post[i].num);
			}
		}
		printf("%d\n",num.top());
		num.pop();
	}
	return 0;
}
