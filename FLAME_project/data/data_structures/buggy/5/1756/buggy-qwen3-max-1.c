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
    for(int k=0;k<i+1;k++) // @@ [Loop bound is incorrect: should be k <= i, but i was incremented only after reading non-last terms; the last term is stored at index i, so loop should run from 0 to i inclusive. However, due to input logic, i is one less than the actual count. The correct number of terms in sn1 is i+1, so this loop condition is actually correct. But the real issue is in the merging logic below.]
    {
        for(int l=0;l<j+1;l++) // @@ [Same as above: j+1 is correct if j is last valid index. Input logic stores first term at 0, and increments i AFTER storing, so when break happens, i is the index of last stored element. So total terms = i+1. So loop bounds are correct. The real bug is elsewhere.]
        {
            sn[op].c=sn1[k].c*sn2[l].c;
            sn[op].d=sn1[k].d+sn2[l].d;
            op++;
        }
    }
    qsort(sn,op,sizeof(struct node),cmp);
    for(int k=0;k<op;k++)
    {
        if(k!=0&&sn[k].d==sn[k-1].d)
        {
            //printf("%d\n",k);
            if(sn[k-1].c==0)
            {
                int flag=0;
                for(int l=k;l>-1;l--) // @@ [This backward search is flawed: it starts at l=k and goes down, but when it finds a non-zero coefficient with same degree, it adds current term's coefficient to it. However, because terms are sorted in descending order, all same-degree terms should be consecutive. This complex logic is unnecessary and buggy. In particular, it may miss merging or double-merge. Also, setting sn[k].c=0 doesn't prevent later terms from trying to merge into it. The expected output differs at exponent 26: buggy has 142, expected 157 — meaning two terms (e.g., 18x^9 * 26x^15 = 468x^24? Wait, no — actually, 18x^9 * 6x^0 = 108x^9, etc. The discrepancy at 26 suggests missing merge of two terms that sum to 157 instead of 142. The merging logic fails to combine all like terms correctly because it only checks immediate predecessor and handles zeroed terms poorly.]
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