#include<stdio.h>
#include<stdlib.h>
struct fml
{
    int coe;
    int pow;
}a[1001],b[1001],ans[1001];
int cmp(const void *a,const void *b)
{
    struct fml *aa=(struct fml*)a;
    struct fml *bb=(struct fml*)b;
    if(aa->pow<bb->pow) return 1;
    else return -1; // @@ This line: cmp should return 0 for equal powers to ensure correct sorting; returning -1 for equal powers may cause undefined behavior and prevent like terms from being contiguous.
}
int main()
{
    int x,y,cnt1=0,cnt2=0,cnt3=0;
    char c;
    do
    {
        scanf("%d%d%c",&x,&y,&c);
        a[cnt1].coe=x,a[cnt1].pow=y;
        cnt1++;
    } while (c!='\n');
    do
    {
        scanf("%d%d%c",&x,&y,&c);
        b[cnt2].coe=x,b[cnt2].pow=y;
        cnt2++;
    } while (c!='\n');
    // for(int i=0;i<cnt1;++i) 
    //     printf("%d ",a[i].coe);
    // printf("\n");
    // for(int j=0;j<cnt2;++j)
    //     printf("%d ",b[j].coe);
    for(int i=0;i<cnt1;++i)
        for(int j=0;j<cnt2;++j)
        {
            ans[cnt3].coe=a[i].coe*b[j].coe;
            ans[cnt3].pow=a[i].pow+b[j].pow;
            cnt3++;
        }
    qsort(ans,cnt3,sizeof(struct fml),cmp);
    for(int i=0;i<cnt3;++i)
    {
        int j=i+1;
        while(j<cnt3&&ans[i].pow==ans[j].pow) ans[i].coe+=ans[j].coe,j++;
        i=j-1; // @@ This line: the loop does not remove duplicate terms that have been summed; they remain in the array and will be printed, causing repeated exponents. A proper combination should either shift remaining elements or use a separate output index.
    }
    for(int i=0;i<cnt3;++i)
        printf("%d %d ",ans[i].coe,ans[i].pow);
    return 0;
}