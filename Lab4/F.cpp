#pragma GCC optimize(2)
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int maxi[510],mini[510],mat[510][510],min_ind[510],max_ind[510],max_front,max_rear,min_front,min_rear;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}
		int res=0,pointer;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				max_front=min_front=max_rear=min_rear=0;
				for(int k=0;k<n;k++)
				{
					if(j==i)
					{
						maxi[k]=mat[j][k];
						mini[k]=mat[j][k];
					}
					else
					{
						maxi[k]=max(maxi[k],mat[j][k]);
						mini[k]=min(mini[k],mat[j][k]);
					}
				}
				pointer=0;
				for(int k=0;k<n;k++)
				{
					while(max_rear>max_front&&maxi[max_ind[max_rear-1]]<maxi[k])
					{
						max_rear--;
					}
					max_ind[max_rear++]=k;
					while(min_rear>min_front&&mini[min_ind[min_rear-1]]>mini[k])
					{
						min_rear--;
					}
					min_ind[min_rear++]=k;
					while(max_front<max_rear&&min_front<min_rear&&maxi[max_ind[max_front]]-mini[min_ind[min_front]]>m)
					{
						pointer++;
						while(min_front<min_rear&&min_ind[min_front]<pointer)
						{
							min_front++;
						}
						while(max_front<max_rear&&max_ind[max_front]<pointer)
						{
							max_front++;
						}
					}
					if(maxi[max_ind[max_front]]-mini[min_ind[min_front]]<=m)
					{
						res=max(res,(j-i+1)*(k-pointer+1));
					}
				}
			}
		}
		printf("%d",res);
		putchar('\n');
	}
	return 0;
}
