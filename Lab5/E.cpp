#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int maxn=(int)1e5+10;
char s1[maxn],s2[maxn];
int len1,len2;
ull hash1[maxn],hash2[maxn],xp[maxn];
void init()
{
    xp[0]=1;
    for(int i=1;i<maxn;i++)
        xp[i]=xp[i-1]*13331;
    return ;
}
void make_hash(char str[],ull*hash_)
{
    int len=strlen(str);
    hash_[len]=0;
    for(int i=len-1;i>=0;i--)
    {
        hash_[i]=hash_[i+1]*13331+str[i]-'A'+1;
    }
    return;
}
ull Get_hash(int i,int L,ull*hash_)
{
    return hash_[i]-hash_[i+L]*xp[L];
}
ull hashcode[maxn];
bool check(int num)
{
	if(num>len1||num>len2)
	{
		return false;
	}
	for(int i=0;i<=len1-num;i++)
	{
		hashcode[i]=Get_hash(i,num,hash1);
	}
	sort(hashcode,hashcode+len1-num+1);
	for(int i=0;i<=len2-num;i++)
	{
		ull tmp_hash=Get_hash(i,num,hash2);
		if(binary_search(hashcode,hashcode+len1-num+1,tmp_hash))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	init();
	scanf("%s%s",s1,s2);
	len1=strlen(s1);
	len2=strlen(s2);
	make_hash(s1,hash1);
	make_hash(s2,hash2);
	int l=0,r=min(len1,len2),mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if(!check(l))
	{
		l--;
	}
	printf("%d\n",l);
	return 0;
}
