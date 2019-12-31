#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
	int x,y;
};
int get_size(int x,int y)
{
	int top=max(x,y),res=2;
	while(res<top)
	{
		res<<=1;
	}
	return res;
}
int get_size(long long num)
{
	int res=2;
	while((long long)res*res<num)
	{
		res<<=1;
	}
	return res;
}
long long get_num(int x,int y,int size)
{
	if(size==2)
	{
		if(x==1&&y==1)
		{
			return 1;
		}
		if(x==2&&y==1)
		{
			return 2;
		}
		if(x==1&&y==2)
		{
			return 4;
		}
		return 3;
	}
	if(x<=size>>1&&y<=size>>1)
	{
		return get_num(x,y,size>>1);
	}
	if(x<=size>>1&&y>size>>1)
	{
		return ((long long)size*size>>2)*3+get_num(x,y-(size>>1),size>>1);
	}
	if(x>size>>1&&y<=size>>1)
	{
		return (long long)(size>>1)*(size>>1)+get_num(x-(size>>1),y,size>>1);
	}
	return (long long)size*(size>>1)+get_num(x-(size>>1),y-(size>>1),size>>1);
}
point get_point(long long num,int size)
{
	point res;
	if(size==2)
	{
		if(num==1)
		{
			res.x=1;
			res.y=1;
		}
		else if(num==2)
		{
			res.x=2;
			res.y=1;
		}
		else if(num==3)
		{
			res.x=2;
			res.y=2;
		}
		else
		{
			res.x=1;
			res.y=2;
		}
	}
	else
	{
		point tmp;
		long long quarter_size=(long long)size*size>>2;
		if(num<=quarter_size)
		{
			tmp=get_point(num,size>>1);
			res=tmp;
		}
		else if(num<=quarter_size<<1)
		{
			tmp=get_point(num-quarter_size,size>>1);
			res.x=(size>>1)+tmp.x;
			res.y=tmp.y;
		}
		else if(num<=quarter_size*3)
		{
			tmp=get_point(num-(quarter_size<<1),size>>1);
			res.x=(size>>1)+tmp.x;
			res.y=(size>>1)+tmp.y;
		}
		else
		{
			tmp=get_point(num-quarter_size*3,size>>1);
			res.x=tmp.x;
			res.y=(size>>1)+tmp.y;
		}
	}
	return res;
}
char s[101],pos=0;
long long get_num(int index)
{
	long long res=0;
	for(int i=index;;i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			pos=i;
			break;
		}
		res=res*10+(s[i]-'0');
	}
	return res;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		if(s[0]=='(')
		{
			pos=0;
			int x=get_num(1);
			int y=get_num(pos+1);
			int size=get_size(x,y);
			printf("%lld\n",get_num(x,y,size));
		}
		else
		{
			long long num=get_num(0);
			int size=get_size(num);
			point res=get_point(num,size);
			printf("(%d,%d)\n",res.x,res.y);
		}
	}
	return 0;
}
