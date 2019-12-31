#include<cstdio>
#include<stack>
using namespace std;
int a[50001],left[50001],right[50001];
stack<int>s;
stack<int>index;
void clean()
{
	while(!s.empty())
	{
		s.pop();
		index.pop();
	}
}
int push(int i,int ind)
{
	int temp=0;
	while(!s.empty()&&s.top()<i)
	{
		temp=index.top();
		s.pop();
		index.pop();
	}
	s.push(i);
	index.push(ind);
	return temp;
}
int main()
{
	int T,kcase=0;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		clean();
		for(int i=0;i<n;i++)
		{
			left[i]=push(a[i],i+1);
		}
		clean();
		for(int i=n-1;i>=0;i--)
		{
			right[i]=push(a[i],i+1);
		}
		printf("Case %d:\n",++kcase);
		for(int i=0;i<n;i++)
		{
			printf("%d %d\n",left[i],right[i]);
		}
	}
	return 0;
}
