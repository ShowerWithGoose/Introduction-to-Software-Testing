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
    while(scanf("%d%d",&s[t].num,&s[t].power)!=EOF) t++; // @@ [Relies on global 't' being 0 initially, but since 't' is uninitialized, this leads to reading/writing at arbitrary memory locations. Also, this loop assumes both polynomials are on one line or EOF-separated, but problem states each polynomial ends with a newline, so this may read both polynomials as one sequence without detecting the line break.]
    int len1=0,len2=0;
    for(int i=0;i<t;i++)
    {
        if(s[i].power<s[i+1].power) // @@ [Accesses s[i+1] when i = t-1, which is out-of-bounds (undefined behavior). Also, logic assumes that the first polynomial is in descending order and the second starts with a lower exponent, but input order is not guaranteed to switch exactly once from high-to-low then low-to-high. This method of splitting polynomials is fundamentally flawed.]
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
        while(ans[j].power==ans[i].power) // @@ [When j reaches cnt, ans[j] is out-of-bounds, causing undefined behavior. Loop condition does not check j < cnt.]
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}