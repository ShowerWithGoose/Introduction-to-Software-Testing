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
    while(scanf("%d%d",&s[t].num,&s[t].power)!=EOF) t++; // @@ The input format specifies two separate polynomials terminated by newlines, but this code reads all integers into a single array until EOF. It fails to distinguish between the two polynomials correctly, especially since the problem description implies a specific structure (two lines) rather than a stream of pairs until EOF. Furthermore, the logic to split `s` into `a` and `b` relies on finding a specific exponent order break which is not guaranteed by the input format description (coefficients can be in any order? No, "descending order" is usually implied or standard, but the split logic `if(s[i].power<s[i+1].power)` assumes the first polynomial's exponents are strictly greater than the second's start, or that there is a clear dip. However, the primary issue is reading input. The problem says "First input... Then input...". Using `scanf` in a loop until EOF consumes both lines. The splitting logic below is fragile and incorrect for general cases.
    int len1=0,len2=0;
    for(int i=0;i<t;i++)
    {
        if(s[i].power<s[i+1].power) // @@ This logic assumes that the exponents in the first polynomial are all greater than the exponents in the second polynomial, or that there is a specific point where the exponent decreases then increases (which wouldn't happen in standard descending input). The input format says "descending order of exponents" for output, but for input it just lists them. Usually, polynomial inputs are also given in descending order. If both are descending, the sequence of exponents in `s` will be descending, then potentially drop, then continue descending. It will NOT have a point where `s[i].power < s[i+1].power` unless the second polynomial has higher degrees than the first, which contradicts the "first polynomial... then second" structure if we assume standard ordering. Even if it did, this split method is fundamentally flawed for separating two distinct polynomial inputs read into one buffer without delimiter awareness.
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
        while(ans[j].power==ans[i].power)
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}