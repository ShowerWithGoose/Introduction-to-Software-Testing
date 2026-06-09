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
    else return -1; // @@ Logical error: qsort comparison function must return 0 when elements are equal. Returning -1 for equality violates strict weak ordering and causes undefined behavior.
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
    for(int i=0;i<cnt1;++i) // @@ Compilation error in C89/ANSI C: variable declaration inside for loop initialization is not allowed; declare 'i' before the loop or compile with C99/C11 standard.
        for(int j=0;j<cnt2;++j) // @@ Compilation error in C89/ANSI C: variable declaration inside for loop initialization is not allowed; declare 'j' before the loop.
        {
            ans[cnt3].coe=a[i].coe*b[j].coe;
            ans[cnt3].pow=a[i].pow+b[j].pow;
            cnt3++;
        }
    qsort(ans,cnt3,sizeof(struct fml),cmp);
    for(int i=0;i<cnt3;++i) // @@ Compilation error in C89/ANSI C: variable declaration inside for loop initialization is not allowed; declare 'i' before the loop.
    {
        int j=i+1;
        while(j<cnt3&&ans[i].pow==ans[j].pow) ans[i].coe+=ans[j].coe,j++; // @@ Logical error: does not handle cases where the merged coefficient becomes 0, which should be excluded from output. Modifying loop variable 'i' inside the loop body can also lead to skipped elements or out-of-bounds access.
        i=j-1;
    }
    for(int i=0;i<cnt3;++i) // @@ Compilation error in C89/ANSI C: variable declaration inside for loop initialization is not allowed; declare 'i' before the loop.
        printf("%d %d ",ans[i].coe,ans[i].pow); // @@ Logical error: prints terms with zero coefficients; should add a condition to skip printing when coefficient is 0.
    return 0;
}