#include<cstdio>
#include<cstring>
using namespace std;
const int dir[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
char sudoku[9][9],s[2];
bool have[9];
bool check_end()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(sudoku[i][j]=='x')
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%s",s);
			sudoku[i][j]=s[0];
			if(j%3==2)
			{
				scanf("%s",s);
			}
		}
	}
	bool is_ok=true;
	while(!check_end())
	{
		bool ok=false;
		for(int i=0;i<9;i++)
		{
			int cnt=0,ind=-1;
			memset(have,false,sizeof(have));
			for(int j=0;j<9;j++)
			{
				if(sudoku[i][j]=='x')
				{
					cnt++;
					ind=j;
				}
				else
				{
					have[sudoku[i][j]-'1']=true;
				}
				if(cnt>1)
				{
					break;
				}
			}
			if(cnt==1)
			{
				ok=true;
				for(int j=0;j<9;j++)
				{
					if(!have[j])
					{
						sudoku[i][ind]=j+'1';
						break;
					}
				}
				break;
			}
		}
		if(ok)
		{
			continue;
		}
		for(int i=0;i<9;i++)
		{
			int cnt=0,ind=-1;
			memset(have,false,sizeof(have));
			for(int j=0;j<9;j++)
			{
				if(sudoku[j][i]=='x')
				{
					cnt++;
					ind=j;
				}
				else
				{
					have[sudoku[j][i]-'1']=true;
				}
				if(cnt>1)
				{
					break;
				}
			}
			if(cnt==1)
			{
				ok=true;
				for(int j=0;j<9;j++)
				{
					if(!have[j])
					{
						sudoku[ind][i]=j+'1';
						break;
					}
				}
				break;
			}
		}
		if(ok)
		{
			continue;
		}
		for(int i=0;i<9;i+=3)
		{
			for(int j=0;j<9;j+=3)
			{
				memset(have,false,sizeof(have));
				int cnt=0,xind=-1,yind=-1;
				for(int k=0;k<9;k++)
				{
					if(sudoku[i+dir[k][0]][j+dir[k][1]]=='x')
					{
						cnt++;
						xind=i+dir[k][0];
						yind=j+dir[k][1];
					}
					else
					{
						have[sudoku[i+dir[k][0]][j+dir[k][1]]-'1']=true;
					}
					if(cnt>1)
					{
						break;
					}
				}
				if(cnt==1)
				{
					ok=true;
					for(int k=0;k<9;k++)
					{
						if(!have[k])
						{
							sudoku[xind][yind]=k+'1';
							break;
						}
					}
					break;
				}
			}
			if(ok)
			{
				break;
			}
		}
		if(!ok)
		{
			is_ok=false;
			break;
		}
	}
	if(is_ok)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				printf("%c ",sudoku[i][j]);
				if(j%3==2)
				{
					printf("| ");
				}
			}
			printf("%c |\n",sudoku[i][8]);
			if(i%3==2)
			{
				printf("\n");
			}
		}
		for(int j=0;j<8;j++)
		{
			printf("%c ",sudoku[8][j]);
			if(j%3==2)
			{
				printf("| ");
			}
		}
		printf("%c |",sudoku[8][8]);
	}
	else
	{
		printf("The test data is incorrect!");
	}
	return 0;
}
