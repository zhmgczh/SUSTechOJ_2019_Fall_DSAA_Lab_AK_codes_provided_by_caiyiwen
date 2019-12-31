#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
bool have[300000];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(have,false,sizeof(have));
		stack<int>slot;
		int n,temp,cnt=1;
		scanf("%d",&n);
		int entry[n],count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			slot.push(temp);
			have[temp]=true;
			while(!slot.empty()&&slot.top()<=cnt)
			{
				entry[count++]=slot.top();
				slot.pop();
				if(entry[count-1]==cnt)
				{
					cnt++;
					while(have[cnt])
					{
						cnt++;
					}
				}
			}
		}
		while(!slot.empty())
		{
			entry[count++]=slot.top();
			slot.pop();
		}
		for(int i=0;i<count;i++)
		{
			printf(i==0?"%d":" %d",entry[i]);
		}
		printf("\n");
	}
	return 0;
}
