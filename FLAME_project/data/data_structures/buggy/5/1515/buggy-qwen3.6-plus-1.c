#include <stdio.h>
#define N 1000010
struct point
{
    int num;
    int power;
};
typedef struct point point;
point s[N];
int t;
point a[N],b[N];
point ans[N];
int cnt;
int cmp(point* a,point* b)
{
    point x=*a;
    point y=*b;
    if(x.power<y.power) return 1;
    else return -1;
}
int main()
{
    while(scanf("%d%d",&s[t].num,&s[t].power)!=EOF) t++;
    int len1=0,len2=0;
    for(int i=0;i<t;i++)
    {
        if(s[i].power<s[i+1].power) // @@ [The logic to split the input into two polynomials is flawed. It assumes the input is sorted by exponent and splits at the first increase, which is incorrect for general polynomial input formats where terms might be descending or arbitrary. More critically, accessing s[i+1] when i == t-1 causes an out-of-bounds read. The problem states input format is two separate lines/polynomials, but this code reads all into one array and tries to guess the split point based on exponent order, which fails if exponents are monotonic decreasing (common) or if the split condition isn't met.]
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
        while(j<cnt && ans[j].power==ans[i].power) // @@ [Missing boundary check j<cnt in the inner while loop condition. If the last group of terms has the same power, j will increment beyond cnt, causing an out-of-bounds access on ans[j].power in the next iteration check.]
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}