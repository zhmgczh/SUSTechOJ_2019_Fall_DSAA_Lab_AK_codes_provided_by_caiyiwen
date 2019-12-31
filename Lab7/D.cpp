#pragma GCC optimize(2)
#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
struct node
{
	node*l;
	node*r;
	int size;
	long long w;
};
int tot=1;
node*create_node(long long w)
{
	node*res=new node;
	res->l=NULL;
	res->r=NULL;
	res->size=1;
	res->w=w;
	return res;
}
void Insert(node*root,node*s)
{
	node*p=root,*q;
	bool left_or_right;
	if(root->w>s->w)
	{
		q=root->l;
		left_or_right=true;
	}
	else
	{
		++root->size;
		q=root->r;
		left_or_right=false;
	}
	while(q)
	{
		p=q;
		if(q->w>s->w)
		{
			q=q->l;
			left_or_right=true;
		}
		else
		{
			++q->size;
			q=q->r;
			left_or_right=false;
		}
	}
	if(left_or_right)
	{
		p->l=s;
	}
	else
	{
		p->r=s;
	}
}
node*find_min(node*root)
{
	while(root->l)
	{
		root=root->l;
	}
	return root;
}
node*find_kth(node*root,int k)
{
	int cnt=0;
	while(cnt<k)
	{
		if(root->size>k-cnt)
		{
			root=root->r;
		}
		else if(root->size==k-cnt)
		{
			return root;
		}
		else
		{
			cnt+=root->size;
			root=root->l;
		}
	}
	return root;
}
long long alpha(long long n)
{
	long long res=n;
	while(n)
	{
		res+=n%10;
		n/=10;
	}
	return res;
}
void free_all(node*root)
{
	if(root!=NULL)
	{
		free_all(root->l);
		free_all(root->r);
		delete root;
	}
}
node*free_remain(node*root,int k)
{
	node*root_tmp=root;
	while(root->size>k)
	{
		root_tmp=root;
		root=root->r;
		free_all(root_tmp->l);
		delete root_tmp;
	}
	return root;
}
int main()
{
	int t,k,s;
	scanf("%d%d%d",&t,&k,&s);
	int time=t/100*100;
	long long last_ans=s;
	node*root=create_node(alpha(1+last_ans));
	for(int i=2;i<=min(k,time);++i)
	{
		Insert(root,create_node(alpha(i+last_ans)));
		if(i%100==0)
		{
			last_ans=find_min(root)->w;
			printf("%lld ",last_ans);
		}
	}
	for(int i=k+1;i<=time;++i)
	{
		Insert(root,create_node(alpha(i+last_ans)));
		root=free_remain(root,k);
		if(i%100==0)
		{
			last_ans=find_kth(root,k)->w;
			printf("%lld ",last_ans);
		}
	}
	return 0;
}
