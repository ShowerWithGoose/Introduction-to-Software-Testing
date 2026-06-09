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
        i++; // @@ [Loop increments i after reading a term, but the last valid index becomes i, not i-1. However, the multiplication loop uses i+1, which overcounts by one because i was not incremented for the last term due to break before i++. This causes accessing uninitialized elements in sn1/sn2.]
    }
    while(1)
    {
        scanf("%d%d",&sn2[j].c,&sn2[j].d);
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: j is not incremented for the last term, so the number of terms is j+1, but the loop condition breaks before incrementing j, leading to off-by-one error in multiplication loop.]
    }
    int op=0;
    for(int k=0;k<i+1;k++) // @@ [Should be k <= i (or k < i+1 only if i was correctly counting all terms). But since i wasn't incremented for the last term, i+1 accesses sn1[i] which was never assigned (only indices 0..i-1 and the last term stored at i without increment). So this accesses garbage data.]
    {
        for(int l=0;l<j+1;l++) // @@ [Same off-by-one error as above with j.]
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
                for(int l=k;l>-1;l--) // @@ [Loop condition l > -1 may cause out-of-bounds access when l becomes -1; also logic for merging like terms is flawed and unnecessarily complex. It should merge all same-degree terms in one pass, not just adjacent ones after sort.]
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