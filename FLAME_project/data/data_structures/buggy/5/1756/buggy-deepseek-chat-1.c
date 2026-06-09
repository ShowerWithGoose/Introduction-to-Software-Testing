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
    for(int k=0;k<i+1;k++) // @@ Error: The loop condition should be k <= i, not k < i+1, because i is the index of the last element. Using k < i+1 is equivalent but confusing; the real issue is that i and j are not incremented after reading the last term, so i and j are one less than the actual number of terms. For example, if there are 6 terms, i will be 5 after the loop, so k < i+1 means k < 6, which is correct. However, the same logic for j is also correct. The actual bug is in the merging logic below.
    {
        for(int l=0;l<j+1;l++) // @@ Error: Same as above, loop condition should be l <= j, but l < j+1 is equivalent. The real issue is the merging logic.
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
            if(sn[k-1].c==0) // @@ Error: This condition incorrectly handles cases where the previous term's coefficient is zero after merging. The logic for merging same exponents is flawed; it should simply add coefficients of consecutive terms with the same exponent after sorting, but the special case for sn[k-1].c==0 causes incorrect merging, leading to wrong coefficients (e.g., 142 vs 157 in output).
            {
                int flag=0;
                for(int l=k;l>-1;l--)
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