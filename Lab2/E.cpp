#include<cstdio>
#include<cmath>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
int n,p,q;
struct node
{
	int hp,attack;
}entry[(int)2e5+10];
int indexa[(int)2e5+10],t[(int)2e5+10];
long long values[(int)2e5+10];
bool have[(int)2e5+10];
bool cmpa(int a,int b)
{
	return entry[a].hp-entry[a].attack>=entry[b].hp-entry[b].attack;
}
void sort(int b,int e)
{
	if(e-b<=0)
	{
		return;
	}
	int mid=(b+e)>>1,p1=b,p2=mid+1,i=b;
	sort(b,mid);
	sort(mid+1,e);
	while(p1<=mid||p2<=e)
	{
		if(p2>e||(p1<=mid&&cmpa(indexa[p1],indexa[p2])))
		{
			t[i++]=indexa[p1++];
		}
		else
		{
			t[i++]=indexa[p2++];
		}
	}
	for(int i=b;i<=e;i++)
	{
		indexa[i]=t[i];
	}
}
int main()
{
	scanf("%d%d%d",&n,&p,&q);
	long long max_mul=pow(2,p),ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&entry[i].hp,&entry[i].attack);
		indexa[i]=i;
		values[i]=max_mul*entry[i].hp-entry[i].attack;
		ans+=entry[i].attack;
	}
	sort(0,n-1);
	int cnt=0;
	long long tmp=ans;
	for(int i=0;i<n;i++)
	{
		if(cnt==q||entry[indexa[i]].hp<=entry[indexa[i]].attack)
		{
			break;
		}
		cnt++;
		tmp+=entry[indexa[i]].hp-entry[indexa[i]].attack;
		have[indexa[i]]=true;
	}
	if(!q)
	{
		printf("%lld\n",ans);
	}
	else
	{
		long long res=0,temp;
		for(int i=0;i<n;i++)
		{
			if(have[i])
			{
				temp=max(tmp,tmp-(entry[i].hp-entry[i].attack)+values[i]);
			}
			else
			{
				if(cnt<q)
				{
					temp=max(tmp,tmp+values[i]);
				}
				else
				{
					temp=max(tmp,tmp-(entry[indexa[cnt-1]].hp-entry[indexa[cnt-1]].attack)+values[i]);
				}
			}
			res=max(res,temp);
		}
		printf("%lld\n",res);
	}
	return 0;
}
