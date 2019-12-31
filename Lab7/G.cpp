#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=(int)1e6+10;
const long long mod=1000000000LL;
const long long inv_3=666666667LL;
long long s[maxn],t[maxn];
long long n,current_num,res,ac,bc,pr,l_num,r_num,num,tmp;
class SplayNode
{
public:
	SplayNode*L,*R,*F;
	long long lnum,rnum,size;
	bool lazy;
	SplayNode(long long l_num,long long r_num)
	{
		lnum=l_num;
		rnum=r_num;
		size=abs(r_num-l_num)+1;
		lazy=false;
		L=R=F=NULL;
	}
	void leftrotate()
	{
		SplayNode*y=F;
		F=y->F;
		if(F!=NULL)
		{
			if(F->L==y)
			{
				F->L=this;
			}
			else
			{
				F->R=this;
			}
		}
		if(R!=NULL)
		{
			R->F=y;
		}
		y->L=R;
		y->F=this;
		this->R=y;
		y->size=(y->L==NULL?0:y->L->size)+(y->R==NULL?0:y->R->size)+abs(y->lnum-y->rnum)+1;
		this->size=(this->L==NULL?0:this->L->size)+(this->R==NULL?0:this->R->size)+abs(this->lnum-this->rnum)+1;
	}
	void rightrotate()
	{ 
		SplayNode*y=F;
		F=y->F;
		if(F!=NULL)
		{
			if(F->L==y)
			{
				F->L=this;
			}
			else
			{
				F->R=this;
			}
		}
		if(L!=NULL)
		{
			L->F=y;
		}
		y->R=L;
		y->F=this;
		this->L=y;
		y->size=(y->L==NULL?0:y->L->size)+(y->R==NULL?0:y->R->size)+abs(y->lnum-y->rnum)+1;
		this->size=(this->L==NULL?0:this->L->size)+(this->R==NULL?0:this->R->size)+abs(this->lnum-this->rnum)+1;
	}
	static void splay(SplayNode*x,SplayNode*SF)
	{
		while(x->F!=SF)
		{
			SplayNode*y=x->F;
			SplayNode*z=y->F;
			if(z==SF)
			{
				if(y->L==x)
				{
					x->leftrotate();
				}
				else
				{
					x->rightrotate();
				}
			}
			else
			{
				if(y->L==x&&z->L==y)
				{
					y->leftrotate();
					x->leftrotate();
				}
				else if(y->L==x&&z->R==y)
				{
					x->leftrotate();
					x->rightrotate();
				}
				else if(y->R==x&&z->R==y)
				{
					y->rightrotate();
					x->rightrotate();
				}
				else
				{
					x->rightrotate();
					x->leftrotate();
				}
			}
		}
	}
	static void putdown(SplayNode*x)
	{
		if(!(x->lazy))
		{
			return;
		}
		if(x->L)
		{
			x->L->lazy=!(x->L->lazy);
		}
		if(x->R)
		{
			x->R->lazy=!(x->R->lazy);
		}
		swap(x->L,x->R);
		swap(x->lnum,x->rnum);
		x->lazy=false;
	}
	static void leftmost_insert(SplayNode*&x,SplayNode*ind)
	{
		if(!x)
		{
			x=ind;
		}
		else
		{
			putdown(x);
			leftmost_insert(x->L,ind);
			x->L->F=x;
		}
	}
	static SplayNode*s_split(SplayNode*x,long long cnt_num)
	{
		putdown(x);
		long long L_size=x->L==NULL?0:x->L->size;
		if(L_size+1<=cnt_num&&L_size+abs(x->lnum-x->rnum)+1>=cnt_num)
		{
			if(L_size+1==cnt_num)
			{
				return NULL;
			}
			SplayNode*top;
			if(x->lnum<x->rnum)
			{
				top=new SplayNode(x->lnum-L_size+cnt_num-1,x->rnum);
				x->rnum=top->lnum-1;
			}
			else
			{
				top=new SplayNode(x->lnum-cnt_num+L_size+1,x->rnum);
				x->rnum=top->lnum+1;
			}
			x->size=(x->L==NULL?0:x->L->size)+(x->R==NULL?0:x->R->size)+abs(x->lnum-x->rnum)+1;
			if(x->R)
			{
				leftmost_insert(x->R,top);
			}
			else
			{
				x->R=top;
				top->F=x;
			}
			return top;
		}
		else if(L_size+1>cnt_num)
		{
			return s_split(x->L,cnt_num);
		}
		else
		{
			return s_split(x->R,cnt_num-L_size-1-abs(x->lnum-x->rnum));
		}
	}
	static void rightmost_insert(SplayNode*&x,SplayNode*ind)
	{
		if(!x)
		{
			x=ind;
		}
		else
		{
			putdown(x);
			rightmost_insert(x->R,ind);
			x->R->F=x;
		}
	}
	static SplayNode*e_split(SplayNode*x,long long cnt_num)
	{
		putdown(x);
		long long L_size=x->L==NULL?0:x->L->size;
		if(L_size+1<=cnt_num&&L_size+abs(x->lnum-x->rnum)+1>=cnt_num)
		{
			if(L_size+abs(x->lnum-x->rnum)+1==cnt_num)
			{
				return NULL;
			}
			SplayNode*top;
			if(x->lnum<x->rnum)
			{
				top=new SplayNode(x->lnum,x->lnum-L_size+cnt_num-1);
				x->lnum=top->rnum+1;
			}
			else
			{
				top=new SplayNode(x->lnum,x->lnum-cnt_num+L_size+1);
				x->lnum=top->rnum-1;
			}
			x->size=(x->L==NULL?0:x->L->size)+(x->R==NULL?0:x->R->size)+abs(x->lnum-x->rnum)+1;
			if(x->L)
			{
				rightmost_insert(x->L,top);
			}
			else
			{
				x->L=top;
				top->F=x;
			}
			return top;
		}
		else if(L_size+1>cnt_num)
		{
			return e_split(x->L,cnt_num);
		}
		else
		{
			return e_split(x->R,cnt_num-L_size-1-abs(x->lnum-x->rnum));
		}
	}
	static SplayNode*find_kth(SplayNode*x,long long cnt_num)
	{
		putdown(x);
		long long L_size=x->L==NULL?0:x->L->size;
		if(L_size+1<=cnt_num&&L_size+abs(x->lnum-x->rnum)+1>=cnt_num)
		{
			return x;
		}
		else if(L_size+1>cnt_num)
		{
			return find_kth(x->L,cnt_num);
		}
		else
		{
			return find_kth(x->R,cnt_num-L_size-1-abs(x->lnum-x->rnum));
		}
	}
	static void prepare(SplayNode*x,SplayNode*y)
	{
		splay(x,NULL);
		splay(y,x);
	}
	static void inorder(SplayNode*u)
	{
		if(u)
		{
			putdown(u);
			inorder(u->L);
			if(!((u->lnum==0&&u->rnum==0)||(u->lnum==n+1&&u->rnum==n+1)))
			{
				l_num=u->lnum-1;
				r_num=u->rnum-1;
				if(l_num==r_num)
				{
					res=(res+l_num%mod*current_num%mod)%mod;
					current_num=(current_num+1)%mod;
				}
				else if(l_num<r_num)
				{
					num=r_num-l_num+1;
					if(num&1LL)
					{
						pr=(num-1)/2%mod*(num%mod)%mod;
					}
					else
					{
						pr=num/2%mod*((num-1)%mod)%mod;
					}
					ac=l_num%mod;
					bc=current_num;
					tmp=((num<<1)-1)%mod;
					res=(res+num%mod*ac%mod*bc%mod)%mod;
					res=(res+pr*((ac+bc)%mod)%mod)%mod;
					res=(res+pr*tmp%mod*inv_3%mod)%mod;
					current_num=(current_num+num)%mod;
				}
				else
				{
					num=l_num-r_num+1;
					if(num&1)
					{
						pr=(num-1)/2%mod*(num%mod)%mod;
					}
					else
					{
						pr=num/2%mod*((num-1)%mod)%mod;
					}
					ac=l_num%mod;
					bc=current_num;
					tmp=((num<<1)-1)%mod;
					res=(res+num%mod*ac%mod*bc%mod)%mod;
					res=(res+pr*((ac-bc+mod)%mod)%mod)%mod;
					tmp=pr*tmp%mod*inv_3%mod;
					while(res<tmp)
					{
						res+=mod;
					}
					res=(res-tmp)%mod;
					current_num=(current_num+num)%mod;
				}
			}
			inorder(u->R);
		}
	}
};
int main()
{
	int k;
	scanf("%lld%d",&n,&k);
	s[0]=t[0]=1;
	for(int i=1;i<k;++i)
	{
		s[i]=(s[i-1]+t[i-1])%n;
		t[i]=(t[i-1]+s[i])%n;
	}
	SplayNode*root=new SplayNode(1,n),*s_ind,*e_ind,*x,*y;
	SplayNode*lowest=new SplayNode(0,0);
	SplayNode*highest=new SplayNode(n+1,n+1);
	root->L=lowest;
	root->R=highest;
	root->size=3;
	lowest->F=root;
	highest->F=root;
	for(int i=1;i<k;++i)
	{
		if(s[i]>t[i])
		{
			swap(s[i],t[i]);
		}
		s_ind=SplayNode::s_split(root,s[i]+2);
		if(s_ind)
		{
			SplayNode::splay(s_ind,NULL);
			root=s_ind;
		}
		e_ind=SplayNode::e_split(root,t[i]+2);
		if(e_ind)
		{
			SplayNode::splay(e_ind,NULL);
			root=e_ind;
		}
		x=SplayNode::find_kth(root,s[i]+1);
		y=SplayNode::find_kth(root,t[i]+3);
		SplayNode::prepare(x,y);
		root=x;
		if(root->R->L)
		{
			root->R->L->lazy=!(root->R->L->lazy);
		}
	}
	current_num=res=0;
	SplayNode::inorder(root);
	printf("%lld\n",res);
	return 0;
}
