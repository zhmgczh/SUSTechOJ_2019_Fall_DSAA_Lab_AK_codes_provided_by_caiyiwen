#include<cstdio>
using namespace std;
int s1[(int)1e3+10],s2[(int)1e3+10];
int n;
int find_pos(int a)
{
	for(int i=0;i<n;++i)
	{
		if(a==s2[i])
		{
			return i;
		}
	}
}
void print_post(int l1,int r1,int l2,int r2)
{
	int m=find_pos(s1[l1]);
	if(m>l2)
	{
		print_post(l1+1,l1+m-l2,l2,m-1);
	}
	if(m<r2)
	{
		print_post(l1+m-l2+1,r1,m+1,r2);
	}
	printf("%d ",s1[l1]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&s1[i]);
		}
		for(int i=0;i<n;++i)
		{
			scanf("%d",&s2[i]);
		}
		print_post(0,n-1,0,n-1);
		putchar('\n');
	}
	return 0;
}
