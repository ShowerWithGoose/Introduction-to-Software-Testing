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
    else return 1; // @@ The comparison function for qsort must return 0 when elements are equal. Returning 1 when p1->a2 <= p2->a2 violates the strict weak ordering requirement, leading to undefined behavior or incorrect sorting, especially when exponents are equal. It should be: if(p1->a2 > p2->a2) return -1; else if(p1->a2 < p2->a2) return 1; else return 0;
    
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
    for(int m=0;m<q-out;m++) // @@ This loop incorrectly assumes that the 'out' zeroed-out terms will be sorted to the end of the array and simply skips the last 'out' elements. However, terms with coefficient 0 (and exponent 0 due to merging logic) might not be at the very end after sorting, or more importantly, valid terms with non-zero coefficients are mixed with zeroed terms. The correct approach is to iterate through all 'q' terms and print only those with non-zero coefficients. Also, if all coefficients become 0, it should print "0 0" or nothing depending on spec, but usually polynomial multiplication results in non-zero polys unless inputs are 0. The current logic fails to print terms that are not among the first q-out sorted items if the zeroed items are scattered.
    {
        printf("%d %d ",ans[m].a1,ans[m].a2);
        
    }
        
        

}