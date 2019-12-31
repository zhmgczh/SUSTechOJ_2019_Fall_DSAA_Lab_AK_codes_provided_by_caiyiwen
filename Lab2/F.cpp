#include<cstdio>
using namespace std;
struct bead
{
    int a,b;
}entry[(int)2e5+10],t[(int)2e5+10];
bool cmp_f(bead a,bead b)
{
    return a.a<=b.a;
}
bool cmp_s(bead a,bead b)
{
    return a.b>=b.b;
}
void sort_f(int b,int e)
{
    if(e-b<=0)
    {
        return;
    }
    int mid=(b+e)>>1,p1=b,p2=mid+1,i=b;
    sort_f(b,mid);
    sort_f(mid+1,e);
    while(p1<=mid||p2<=e)
    {
        if(p2>e||(p1<=mid&&cmp_f(entry[p1],entry[p2])))
        {
            t[i++]=entry[p1++];
        }
        else
        {
            t[i++]=entry[p2++];
        }
    }
    for(int i=b;i<=e;i++)
    {
        entry[i]=t[i];
    }
}
void sort_s(int b,int e)
{
    if(e-b<=0)
    {
        return;
    }
    int mid=(b+e)>>1,p1=b,p2=mid+1,i=b;
    sort_s(b,mid);
    sort_s(mid+1,e);
    while(p1<=mid||p2<=e)
    {
        if(p2>e||(p1<=mid&&cmp_s(entry[p1],entry[p2])))
        {
            t[i++]=entry[p1++];
        }
        else
        {
            t[i++]=entry[p2++];
        }
    }
    for(int i=b;i<=e;i++)
    {
        entry[i]=t[i];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&entry[i].a,&entry[i].b);
        }
        int f_cnt=0;
        for(int i=0;i<n;i++)
        {
            if(entry[i].a<entry[i].b)
            {
                bead tmp=entry[i];
                entry[i]=entry[f_cnt];
                entry[f_cnt]=tmp;
                f_cnt++;
            }
        }
        int s_cnt=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(entry[i].a>entry[i].b)
            {
                bead tmp=entry[i];
                entry[i]=entry[s_cnt];
                entry[s_cnt]=tmp;
                s_cnt--;
            }
        }
        sort_f(0,f_cnt-1);
        sort_s(s_cnt+1,n-1);
        long long ca=entry[0].a,cb=entry[0].b;
        long long res=0;
        for(int i=1;i<n;i++)
        {
            if(entry[i].a==cb)
            {
                res+=cb;
                cb=entry[i].b;
            }
            else if(entry[i].a>cb)
            {
                res+=cb;
                ca+=entry[i].a-cb;
                cb=entry[i].b;
            }
            else
            {
                res+=entry[i].a;
                cb+=entry[i].b-entry[i].a;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
