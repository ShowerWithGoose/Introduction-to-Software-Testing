#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct D1
{
    int x1;
    int y1;
    
}d1[150];
struct D2
{
    int x2;
    int y2;
    
}d2[150];
struct Ans
{
    int a1;
    int a2;
}ans[1500];
int cmp(struct Ans *p1,struct Ans *p2)
{
    if((p1->a2)>(p2->a2))
    return -1;
    else return 1;
    
}
int main()
{
    char c;
    int i=0,j=0,q=0,out=0;
    do{
        scanf("%d%d%c",&d1[i].x1,&d1[i].y1,&c);
        if(d1[i].x1==0) i--;//特殊情况 有项系数为0
        i++;
    }while(c!='\n');//可以记住这种输入方式
    do{
            scanf("%d%d%c",&d2[j].x2,&d2[j].y2,&c);
            if(d2[j].x2==0) j--;
            j++;
        }while(c!='\n');
    for(int k=0;k<i;k++)
    {
        for(int p=0;p<j;p++,q++)
        {
            ans[q].a1=d1[k].x1*d2[p].x2;
            ans[q].a2=d1[k].y1+d2[p].y2;
            
        }
    }
    //合并同类项
    for(int k=0;k<q;k++)
    {
        for(int n=k+1;n<q;n++)
        {
            if(ans[k].a2==ans[n].a2)
            {
                ans[k].a1+=ans[n].a1;
                ans[n].a1=0;ans[n].a2=0;
                out++;
            }
            
        }
    }    
    
    
    qsort(ans,q,sizeof(struct Ans),cmp);    
    for(int m=0;m<q-out;m++) // @@ The loop condition `m<q-out` is incorrect because `qsort` does not remove the zeroed-out elements, it just moves them. The zeroed-out elements (where a1==0 and a2==0, except for the actual zero polynomial case) will likely end up at the end due to sorting, but simply subtracting `out` from the count doesn't guarantee we skip only the merged terms correctly if they aren't contiguous or if `out` counting logic is flawed relative to the sorted array structure. More importantly, the merging logic sets `ans[n]` to 0, but `qsort` sorts based on exponent. Terms with coefficient 0 should ideally be filtered out before printing or during sorting. The current approach prints `q-out` items. If multiple terms merge into one, `out` increments. However, `qsort` rearranges the array. The items set to 0 might not be the last `out` items in the sorted array if their exponent (set to 0) places them elsewhere. For example, if a term with exponent 0 exists legitimately, it conflicts. A safer approach is to filter during print or compact the array before sorting. But specifically here, the error is that we are printing `q-out` elements from the start of the sorted array. The "removed" elements (set to 0 coeff) are scattered or placed based on their new exponent (0). If they sort to the end, it might work, but if they sort to the middle, we print wrong data. Actually, the bigger issue is that `cmp` doesn't handle equality stably or define behavior for equal exponents properly for stability, but mainly, the printing loop assumes the first `q-out` elements are the valid ones. This is false because `qsort` shuffles them. We should iterate through all `q` elements and print only those with non-zero coefficients.
    {
        printf("%d %d ",ans[m].a1,ans[m].a2);
        
    }
        
        

}