#include<cstdio>
using namespace std;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char s[(int)1e5+10];
long long vec[(int)1e5+10][2],x1,y1,x2,y2,n;
long long abso(long long num)
{
	if(num>=0)
	{
		return num;
	}
	return -num;
}
bool check(long long days)
{
	if(abso((long long)x2+days/n*vec[n][0]+vec[days%n][0]-x1)+abso((long long)y2+days/n*vec[n][1]+vec[days%n][1]-y1)<=days)
	{
		return true;
	}
	return false;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld%s",&x1,&y1,&x2,&y2,&n,s);
	vec[0][0]=vec[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		int temp=0;
		if(s[i-1]=='U')
		{
			temp=2;
		}
		else if(s[i-1]=='D')
		{
			temp=3;
		}
		else if(s[i-1]=='L')
		{
			temp=1;
		}
		vec[i][0]=vec[i-1][0]+dir[temp][0];
		vec[i][1]=vec[i-1][1]+dir[temp][1];
	}
	long long l=0,r=(long long)1e18,mid;
	bool ok=false;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
			ok=true;
		}
		else
		{
			l=mid+1;
		}
	}
	if(ok)
	{
		printf("%lld\n",l);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
