#include<cstdio>
using namespace std;
const int maxn=(int)1e5+10;
struct sbt
{
	int l,r,s,key;
}tr[maxn];
int top,root,a[maxn];
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
int select(int&x,int k)
{
	int r=tr[tr[x].l].s+1;
	if(r==k)
	{
		return tr[x].key;
	}
	else if(r<k)
	{
		return select(tr[x].r,k-r);
	}
	else
	{
		return select(tr[x].l,k);
	}
}

void inorder(int &x) {
    if(x == 0) return;
    else {
        inorder(tr[x].l);
        printf("%d ",tr[x].key);
        inorder(tr[x].r);
    }
}
int main()
{
	int m,k;
	scanf("%d%d",&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&a[i]);
	}
	root=0;
	for(int i=1;i<=k;++i)
	{
		insert(root,a[i]);
	}
	for(int i=1;i<=m-k+1;++i)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",select(root,n));
		remove(root,a[i]);
		if(i!=m-k+1)
		{
			insert(root,a[i+k]);
		}
	}
	return 0;
}
