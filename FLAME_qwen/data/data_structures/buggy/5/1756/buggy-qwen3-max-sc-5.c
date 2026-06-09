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
        i++; // @@ [The increment of i happens after the first term is read, so the last valid index is i, not i+1. However, the loop breaks before incrementing i for the last term, so total terms = i+1 is correct. But the real issue is that if input has only one term, i remains 0 and loops below use i+1=1 which is okay. So this line is actually correct.]
    }
    while(1)
    {
        scanf("%d%d",&sn2[j].c,&sn2[j].d);
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same as above; this line is actually correct.]
    }
    int op=0;
    for(int k=0;k<i+1;k++) // @@ [This loop runs from k=0 to k=i (inclusive), which is correct because i was not incremented after reading the last term, so there are i+1 terms.]
    {
        for(int l=0;l<j+1;l++) // @@ [Same as above; correct.]
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
                for(int l=k;l>-1;l--) // @@ [Loop condition 'l>-1' causes out-of-bounds access when l becomes -1; should be 'l>=0'. Also, logic for merging like terms is flawed—it doesn't correctly handle zero coefficients during combination.]
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