#include<cstdio>
#include<map>
using namespace std;
int a[(int)2e6+10],que[(int)2e6+10],front,rear;
map<int,int>have;
int main()
{
	int m;
	scanf("%d",&m);
	int n=0;
	while(scanf("%d",&a[n++])!=EOF&&a[n-1]!=-1);
	front=rear=0;
	int cnt=m-1,last_cnt=0,res=0;
	for(int i=0;i<m;i++)
	{
		while(rear!=front&&que[rear-1]<a[i])
		{
			rear--;
		}
		que[rear++]=a[i];
	}
	while(cnt+1!=n)
	{
		res^=que[front];
		if(a[last_cnt]==que[front])
		{
			front++;
		}
		last_cnt++;
		cnt++;
		while(rear!=front&&que[rear-1]<a[cnt])
		{
			rear--;
		}
		que[rear++]=a[cnt];
	}
	printf("%d\n",res);
	return 0;
}
