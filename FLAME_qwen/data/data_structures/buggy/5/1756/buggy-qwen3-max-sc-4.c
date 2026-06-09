#include<stdio.h>//jiejian ppt
#include<stdlib.h>
struct node
{
    int c;
    int d;
}sn1[10005],sn2[10005],sn[10005];
int cmp(const void *a,const void *b)
{
    return (*(struct node *)b).d-(*(struct node*)a).d;
}
int main()
{
    int i=0,j=0;
    while(1)
    {
        scanf("%d%d",&sn1[i].c,&sn1[i].d);
        if(getchar()=='\n')
        {
            break;
        }
        i++;
    }
    while(1)
    {
        scanf("%d%d",&sn2[j].c,&sn2[j].d);
        if(getchar()=='\n')
        {
            break;
        }
        j++;
    }
    int op=0;
    for(int k=0;k<i+1;k++) // @@ [Loop bound is incorrect: should be k <= i, but since i was not incremented after the last valid input, the loop runs one extra time accessing uninitialized data. The correct upper bound is k <= i, but because i stops at the last valid index, it should be k < i+1 only if i was incremented post-break, which it isn't. Actually, after breaking, i is the index of the last successfully read term, so total terms = i+1. However, in the input loop, i is incremented only when NOT breaking, so after break, i is the count of terms minus 1. Thus, number of terms is i+1, so k from 0 to i inclusive is correct. But wait: in the first loop, if only one term is entered, then i=0, and getchar() sees '\n' and breaks without incrementing i. So terms are from 0 to i (inclusive), total i+1 terms. So k < i+1 is correct. However, the real issue is that if input has zero terms (which shouldn't happen per problem), but more critically, the logic assumes at least one term. But the actual bug is elsewhere.]
    {
        for(int l=0;l<j+1;l++) // @@ [Same issue as above with j: but again, this may be logically correct. However, the real critical error is in the merging/combining like terms logic below.]
        {
            sn[op].c=sn1[k].c*sn2[l].c;
            sn[op].d=sn1[k].d+sn2[l].d;
            op++;
        }
    }
    qsort(sn,op,sizeof(struct node),cmp);
    for(int k=0;k<op;k++)
    {
        if(k!=0&&sn[k].d==sn[k-1].d) // @@ [This condition only checks consecutive duplicates after sorting, but if there are more than two terms with same exponent, it fails to combine all. For example, three terms with same exponent: first two get combined into sn[k-1], third compares with second (now zeroed) and may not combine correctly. Also, setting sn[k].c=0 doesn't remove the term; later printing skips zero coefficients, but the combining logic is flawed because it only looks back one step and doesn't handle chains properly.]
        {
            //printf("%d\n",k);
            if(sn[k-1].c==0) // @@ [This check is problematic: if previous term was zeroed out due to earlier combination, we try to find a non-zero term with same exponent earlier in the array. However, because the array is sorted in descending order, all same-exponent terms are consecutive. So if sn[k-1].c is zero, it means it was combined into an even earlier term. But the loop `for(int l=k;l>-1;l--)` goes backwards from k, but same exponents are only in a contiguous block. This logic is unnecessarily complex and error-prone. Moreover, `l>-1` should be `l>=0`. But more importantly, the entire approach is flawed because after sorting, same-degree terms are adjacent, so we should combine forward or use a better method.]
            {
                int flag=0;
                for(int l=k;l>-1;l--) // @@ [Loop condition `l>-1` is equivalent to `l>=0`, but it's unconventional and might confuse. However, the bigger issue is that this inner loop searches backward through possibly non-same-degree terms, which breaks correctness because same-degree terms are only consecutive after sort. So if sn[k-1].c is zero, it's likely that the actual combined term is at some index < k-1, but only within the same-degree block. However, because we process left-to-right, once a term is zeroed, its degree info is still there, so comparing `sn[k].d == sn[l].d` might match non-consecutive same degrees if there were gaps, but after sort there are no gaps in same-degree groups. Still, this logic is fragile and incorrect in cases with more than two same-degree terms.]
                {
                    if(sn[k].d==sn[l].d&&sn[l].c!=0)
                    {
                        sn[l].c+=sn[k].c;
                        break;
                    }
                }
            }
            else
            sn[k-1].c+=sn[k].c;
            sn[k].c=0;
            
        }
    }
    for(int k=0;k<op;k++)
    {
        if(sn[k].c!=0)
        printf("%d %d ",sn[k].c,sn[k].d);
    }
    return 0;
}