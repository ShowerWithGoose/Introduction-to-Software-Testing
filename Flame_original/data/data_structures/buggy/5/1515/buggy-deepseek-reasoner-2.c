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
int cmp(point* a,point* b) // @@ [Error: Comparator signature must match qsort's expected `int (*)(const void*, const void*)`. This signature causes type mismatch and undefined behavior.]
{
    point x=*a;
    point y=*b;
    if(x.power<y.power) return 1; // @@ [Error: For equal powers, this branch is not taken; the else returns -1, which is non-zero for equal elements, leading to undefined behavior in qsort.]
    else return -1; // @@ [Error: Returns -1 even when powers are equal. qsort requires 0 for equal elements, otherwise behavior is undefined.]
}
int main()
{
    while(scanf("%d%d",&s[t].num,&s[t].power)!=EOF) t++;
    int len1=0,len2=0;
    for(int i=0;i<t;i++)
    {
        if(s[i].power<s[i+1].power) // @@ [Error: Out-of-bounds access when i == t-1, because s[i+1] is beyond the stored data. The loop should go up to i < t-1.]
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
    qsort(ans,cnt,sizeof(ans[0]),cmp); // @@ [Error: Missing `#include <stdlib.h>` for qsort. Also the comparator `cmp` has wrong signature, causing compilation warning/error.]
    //for(int i=0;i<cnt;i++) printf("%d %d\n",ans[i].num,ans[i].power);
    //puts("");
    int i=0;
    while(i<cnt)
    {
        int j=i;
        int res=0;
        while(ans[j].power==ans[i].power) // @@ [Error: Missing bound check `j < cnt`. If all powers are equal, j will eventually go beyond `cnt`, causing out-of-bounds access.]
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}