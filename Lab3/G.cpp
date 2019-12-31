#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=(long long)1e6;
const long long inv_3=666667;
long long s[(int)5e3+10],t[(int)5e3+10];
int Prev[(int)3e4+10],Next[(int)3e4+10];
struct node
{
	long long l,r;
}w[(int)3e4+10];
int tail,tot;
long long abso(long long num)
{
	return num<0?-num:num;
}
void add_seg(long long l,long long r)
{
	w[tot].l=l;
	w[tot].r=r;
	Next[tot]=Next[tail];
	Prev[Next[tail]]=tot;
	Next[tail]=tot;
	Prev[tot]=tail;
	tail=tot;
	tot++;
}
long long mul(long long a,long long b)
{
	return a%mod*(b%mod)%mod;
}
int main()
{
	long long n;
	int k;
	scanf("%lld%d",&n,&k);
	s[0]=t[0]=1;
	for(int i=1;i<k;i++)
	{
		s[i]=(s[i-1]+t[i-1])%n;
		t[i]=(t[i-1]+s[i])%n;
	}
	Next[0]=Prev[0]=tail=0;
	tot=1;
	add_seg(0,n-1);
	int head,a,b,c,d,tnext,start,end;
	long long num,temp,next_num;
	for(int i=1;i<k;i++)
	{
		head=Next[0];
		num=0;
		if(s[i]>t[i])
		{
			swap(s[i],t[i]);
		}
		else if(s[i]==t[i])
		{
			continue;
		}
		while(!(num<=s[i]&&num+abso(w[head].r-w[head].l)>=s[i]))
		{
			num+=abso(w[head].r-w[head].l)+1;
			head=Next[head];
		}
		if(num==s[i])
		{
			start=head;
			c=Prev[start];
		}
		else
		{
			temp=w[head].r;
			tail=head;
			if(w[head].l<=w[head].r)
			{
				w[head].r-=num+w[head].r-w[head].l-s[i]+1;
				add_seg(w[head].r+1,temp);
			}
			else
			{
				w[head].r+=num+w[head].l-w[head].r-s[i]+1;
				add_seg(w[head].r-1,temp);
			}
			start=tail;
			c=Prev[start];
			num=s[i];
		}
		head=start;
		while(!(num<=t[i]&&num+abso(w[head].r-w[head].l)>=t[i]))
		{
			swap(w[head].l,w[head].r);
			tnext=Next[head];
			if(head!=start)
			{
				a=Prev[head];
				b=head;
				Next[b]=a;
				Prev[a]=b;
			}
			num+=abso(w[head].r-w[head].l)+1;
			head=tnext;
		}
		if(num+abso(w[head].r-w[head].l)==t[i])
		{
			end=head;
			d=Next[head];
		}
		else
		{
			temp=w[head].r;
			tail=head;
			if(w[head].l<=w[head].r)
			{
				w[head].r-=num+w[head].r-w[head].l-t[i];
				add_seg(w[head].r+1,temp);
			}
			else
			{
				w[head].r+=num+w[head].l-w[head].r-t[i];
				add_seg(w[head].r-1,temp);
			}
			end=Prev[tail];
			d=Next[end];
		}
		if(end!=start)
		{
			a=end;
			b=Prev[end];
			Next[a]=b;
			Prev[b]=a;
		}
		swap(w[end].l,w[end].r);
		Next[c]=end;
		Prev[end]=c;
		Next[start]=d;
		Prev[d]=start;
	}
	head=Next[0];
	long long current_num=0,res=0,ac,bc,pr;
	while(head!=0)
	{
		//printf("%lld %lld\n",w[head].l,w[head].r);
		if(w[head].l==w[head].r)
		{
			w[head].l%=mod;
			res=(res+w[head].l*current_num)%mod;
			current_num=(current_num+1)%mod;
		}
		else if(w[head].l<w[head].r)
		{
			num=w[head].r-w[head].l+1;
			if(num&1)
			{
				pr=(num-1)/2%mod*num%mod;
			}
			else
			{
				pr=num/2%mod*(num-1)%mod;
			}
			ac=w[head].l%mod;
			bc=current_num;
			num%=mod;
			res=(res+num*ac*bc%mod+pr*(ac+bc)%mod+pr*((num<<1)-1)%mod*inv_3%mod)%mod;
			current_num=(current_num+num)%mod;
		}
		else
		{
			num=w[head].l-w[head].r+1;
			if(num&1)
			{
				pr=(num-1)/2%mod*num%mod;
			}
			else
			{
				pr=num/2%mod*(num-1)%mod;
			}
			ac=w[head].l%mod;
			bc=current_num;
			num%=mod;
			res=(res+num*ac*bc%mod+pr*(ac-bc+mod)%mod-pr*((num<<1)-1)%mod*inv_3%mod+mod)%mod;
			current_num=(current_num+num)%mod;
		}
		head=Next[head];
	}
	printf("%lld\n",res);
	return 0;
}
