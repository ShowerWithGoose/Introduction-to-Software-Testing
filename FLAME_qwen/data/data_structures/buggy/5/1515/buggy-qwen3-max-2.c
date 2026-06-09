#include <stdio.h>
#define N 1000010
struct point
{
    int num;
    int power;
};
typedef struct point point;
point s[N];
int t; // @@ [Global variable 't' is uninitialized, leading to undefined behavior when used as an index in 's[t]'. It should be initialized to 0.]
point a[N],b[N];
point ans[N];
int cnt; // @@ [Global variable 'cnt' is uninitialized. It should be initialized to 0 to correctly count the number of terms in 'ans'.]
int cmp(point* a,point* b)
{
    point x=*a;
    point y=*b;
    if(x.power<y.power) return 1;
    else return -1;
}
int main()
{
    while(scanf("%d%d",&s[t].num,&s[t].power)!=EOF) t++; // @@ [Relies on uninitialized 't'; also, input parsing assumes both polynomials are on the same line or continuous input without newline separation, which contradicts the problem's input format specifying each polynomial ends with a newline. This causes incorrect splitting into len1/len2.]
    int len1=0,len2=0;
    for(int i=0;i<t;i++)
    {
        if(s[i].power<s[i+1].power) // @@ [Accesses s[i+1] when i = t-1, which is out-of-bounds (undefined behavior). Also, logic assumes the first polynomial is in descending order and the second starts with a higher exponent, which is not guaranteed by input format. Input gives terms in descending order per polynomial, so the break condition is flawed.]
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
        while(ans[j].power==ans[i].power) // @@ [When i is at the last element (i == cnt-1), j becomes cnt, and ans[j] accesses out-of-bounds memory, causing undefined behavior. Loop condition should also check j < cnt.]
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}