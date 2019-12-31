#include<cstdio>
#define abs(a) ((a)>0?(a):(-(a)))
const int maxn=(int)8e4+10;
struct sbt
{
	int l,r,s;
	long long key;
}tr[maxn];
int top,root;
void left_rot(int&x)
{
	int y=tr[x].r;
	tr[x].r=tr[y].l;
	tr[y].l=x;
	tr[y].s=tr[x].s;
	tr[x].s=tr[tr[x].l].s+tr[tr[x].r].s+1;
	x=y;
}
void right_rot(int&x)
{
	int y=tr[x].l;
	tr[x].l=tr[y].r;
	tr[y].r=x;
	tr[y].s=tr[x].s;
	tr[x].s=tr[tr[x].l].s+tr[tr[x].r].s+1;
	x=y;
}
void maintain(int&x,bool flag)
{
	if(flag==0)
	{
		if(tr[tr[tr[x].l].l].s>tr[tr[x].r].s)
		{
			right_rot(x);
		}
		else if(tr[tr[tr[x].l].r].s>tr[tr[x].r].s)
		{
			left_rot(tr[x].l);
			right_rot(x);
		}
		else
		{
			return;
		}
	}
	else
	{
		if(tr[tr[tr[x].r].r].s>tr[tr[x].l].s)
		{
			left_rot(x);
		}
		else if(tr[tr[tr[x].r].l].s>tr[tr[x].l].s)
		{
			right_rot(tr[x].r);
			left_rot(x);
		}
		else
		{
			return;
		}
	}
	maintain(tr[x].l,0);
	maintain(tr[x].r,1);
}
void insert(int&x,int key)
{
	if(x==0)
	{
		x=++top;
		tr[x].l=tr[x].r=0;
		tr[x].s=1;
		tr[x].key=key;
	}
	else
	{
		tr[x].s++;
		if(key<tr[x].key)
		{
			insert(tr[x].l,key);
		}
		else
		{
			insert(tr[x].r,key);
		}
		maintain(x,key>=tr[x].key);
	}
}
int remove(int&x,int key)
{
	int k;
	tr[x].s--;
	if(key==tr[x].key||(key<tr[x].key&&tr[x].l==0)||(key>tr[x].key&&tr[x].r==0))
	{
		k=tr[x].key;
		if(tr[x].l&&tr[x].r)
		{
			tr[x].key=remove(tr[x].l,tr[x].key+1);
		}
		else
		{
			x=tr[x].l+tr[x].r;
		}
	}
	else if(key>tr[x].key)
	{
		k=remove(tr[x].r,key);
	}
	else if(key<tr[x].key)
	{
		k=remove(tr[x].l,key);
	}
	return k;
}
int pred(int &x,int y,int key)
{
	if(x==0)
	{
		return y;
	}
	if(tr[x].key<=key)
	{
		return pred(tr[x].r,x,key);
	}
	else
	{
		return pred(tr[x].l,y,key);
	}
}
int succ(int&x,int y,int key)
{
	if(x==0)
	{
		return y;
	}
	if(tr[x].key>=key)
	{
		return succ(tr[x].l,x,key);
	}
	else
	{
		return succ(tr[x].r,y,key);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int root0=0,root1=0,op,res1,res2,res;
	long long ans=0,num;
	while(n--)
	{
		scanf("%d%lld",&op,&num);
		if(op==0)
		{
			res=0;
			res1=pred(root1,0,num);
			res2=succ(root1,0,num);
			if(res1)
			{
				res=res1;
			}
			if(res2&&(res==0||abs(tr[res2].key-num)<abs(tr[res].key-num)))
			{
				res=res2;
			}
			if(res)
			{
				ans+=abs(tr[res].key-num);
				remove(root1,tr[res].key);
			}
			else
			{
				insert(root0,num);
			}
		}
		else
		{
			res=0;
			res1=pred(root0,0,num);
			res2=succ(root0,0,num);
			if(res1)
			{
				res=res1;
			}
			if(res2&&(res==0||abs(tr[res2].key-num)<abs(tr[res].key-num)))
			{
				res=res2;
			}
			if(res)
			{
				ans+=abs(tr[res].key-num);
				remove(root0,tr[res].key);
			}
			else
			{
				insert(root1,num);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
