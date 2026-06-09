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
    if(aa->pow<bb->pow) return 1; // @@ The comparator does not return 0 for equal powers, violating the strict weak ordering requirement of qsort. Should return 0 when powers are equal.
    else return -1; // @@ See above; when powers are equal, returning -1 is inconsistent and may cause undefined behavior.
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
        i=j-1; // @@ After combining, duplicate entries are still present in the array and cnt3 is not updated. These duplicates will be printed later, causing extra terms in the output. Should remove them by shifting the array or adjust the printing loop.
    }
    for(int i=0;i<cnt3;++i) // @@ Prints all cnt3 entries, including duplicate terms that were not removed. Should only print distinct combined terms.
        printf("%d %d ",ans[i].coe,ans[i].pow);
    return 0;
}