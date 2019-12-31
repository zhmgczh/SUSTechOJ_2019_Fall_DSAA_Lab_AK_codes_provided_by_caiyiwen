#include<cstdio>
using namespace std;
const int maxn=(int)1e6+10;
int x[maxn],p[maxn];
int lower_bound(int *array, int size, int key)
{
    int first = 0, middle;
    int half, len;
    len = size;

    while(len > 0) {
        half = len >> 1;
        middle = first + half;
        if(array[middle] < key) {
            first = middle + 1;          
            len = len-half-1;
        }
        else
            len = half;
    }
    return first;
}
int main()
{
	int t,n;
	scanf("%d%d",&t,&n);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=0;i<t;i++)
	{
		int buy=lower_bound(p,n,x[i]);
		if(buy<n&&p[buy]==x[i])
		{
			printf("Meow\n");
		}
		else
		{
			while(buy>=0&&(buy>=n||p[buy]>=x[i]))
			{
				buy--;
			}
			if(buy>=0)
			{
				printf("%d\n",x[i]-p[buy]);
			}
			else
			{
				printf("%d\n",x[i]);
			}
		}
	}
	return 0;
}
