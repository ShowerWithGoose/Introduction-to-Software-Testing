#include <stdio.h>
#define N 1000010
struct point
{
    int num;
    int power;
};
typedef struct point point;
point s[N];
int t; // @@ [Global variable 't' is uninitialized, leading to undefined behavior when used as an index in 's[t]']
point a[N],b[N];
point ans[N];
int cnt; // @@ [Global variable 'cnt' is uninitialized; should be initialized to 0 before use in loop]
int cmp(point* a,point* b)
{
    point x=*a;
    point y=*b;
    if(x.power<y.power) return 1;
    else return -1;
}
int main()
{
    while(scanf("%d%d",&s[t].num,&s[t].power)!=EOF) t++; // @@ [Relies on uninitialized 't'; also assumes input ends with EOF but problem states input ends with newline, causing potential infinite loop or incorrect parsing]
    int len1=0,len2=0;
    for(int i=0;i<t;i++)
    {
        if(s[i].power<s[i+1].power) // @@ [Accesses s[i+1] which may be out-of-bounds when i == t-1; also logic assumes a strict drop in exponent to separate polynomials, which is not guaranteed by input format]
        {
            len1=i+1;
            len2=t-i-1;
            break;
        }
    }
    for(int i=0;i<len1;i++) a[i]=s[i];
    for(int i=0;i<len2;i++) b[i]=s[i+len1];
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            ans[cnt].num=a[i].num*b[j].num;
            ans[cnt++].power=a[i].power+b[j].power;
        }
    }
    qsort(ans,cnt,sizeof(ans[0]),cmp);
    //for(int i=0;i<cnt;i++) printf("%d %d\n",ans[i].num,ans[i].power);
    //puts("");
    int i=0;
    while(i<cnt)
    {
        int j=i;
        int res=0;
        while(ans[j].power==ans[i].power) // @@ [May access ans[j] beyond array bounds when j reaches cnt without checking j < cnt]
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}