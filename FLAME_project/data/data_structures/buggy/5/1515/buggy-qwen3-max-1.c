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
        if(s[i].power<s[i+1].power) // @@ [This condition assumes the input switches from first to second polynomial when exponent increases, but the problem states both polynomials are given in descending order. So the second polynomial also starts with highest exponent, and there's no guarantee that s[i].power < s[i+1].power at the boundary. In fact, both polynomials are in descending order, so the entire input is non-increasing until the split, then again non-increasing. Thus this logic fails to correctly split the two polynomials.]
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
        while(ans[j].power==ans[i].power) // @@ [This loop may access ans[j] beyond cnt when j reaches cnt, causing undefined behavior. The condition should also check j < cnt.]
        {
            res+=ans[j].num;
            j++;
        }
        printf("%d %d ",res,ans[i].power);
        i=j;
    }
    return 0;
}