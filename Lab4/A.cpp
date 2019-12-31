#include<cstdio>
using namespace std;
int que[(int)2e7+10],front,rear;
int main()
{
	int n;
	scanf("%d",&n);
	front=0,rear=0;
	char op[2];
	int oprand;
	while(n--)
	{
		scanf("%s",op);
		if(op[0]=='E')
		{
			scanf("%d",&oprand);
			que[rear]=oprand;
			rear++;
		}
		else if(op[0]=='D')
		{
			front++;
		}
		else
		{
			printf("%d\n",que[front]);
		}
	}
	while(front!=rear)
	{
		printf("%d ",que[front++]);
	}
	return 0;
}
