#include<cstdio>
using namespace std;
const int maxn=(int)1e5+10;
int n,HeapSize;
long long Heap[maxn+1];
void HeapUp(int p)
{
	int q=p>>1;
	long long a=Heap[p];
	while(q)
	{
		if(a<Heap[q])
		{
			Heap[p]=Heap[q];
		}
		else
		{
			break;
		}
		p=q;
		q=p>>1;
	}
	Heap[p]=a;
}
void AddToHeap(long long a)
{
	Heap[++HeapSize]=a;
	HeapUp(HeapSize);
}
void HeapDown(int p)
{
	int q=p<<1;
	long long a=Heap[p];
	while(q<=HeapSize)
	{
		if(q<HeapSize&&Heap[q+1]<Heap[q])
		{
			q++;
		}
		if(Heap[q]<a)
		{
			Heap[p]=Heap[q];
		}
		else
		{
			break;
		}
		p=q;
		q=p<<1;
	}
	Heap[p]=a;
}
long long GetTopFromHeap()
{
	long long TopElement=Heap[1];
	Heap[1]=Heap[HeapSize--];
	HeapDown(1);
	return TopElement;
}
void BuildHeap()
{
	for(int i=HeapSize;i>0;--i)
	{
		HeapDown(i);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&Heap[i]);
		}
		HeapSize=n;
		BuildHeap();
		long long res=0;
		while(HeapSize)
		{
			long long tmp=0;
			tmp=GetTopFromHeap();
			if(HeapSize)
			{
				tmp+=GetTopFromHeap();
				res+=tmp;
				AddToHeap(tmp);
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
