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
    for(int k=0;k<i+1;k++) // @@ Error: Loop condition should be k<=i or k<i+1, but i is the index of the last element, so i+1 is correct. However, the issue is that i and j are not incremented after reading the last term, so i and j are the indices of the last term, not the count. The loop should run i+1 times, which is correct. But the real problem is that the input reading logic is flawed: after reading the last term, getchar() reads the newline and breaks, but i and j are not incremented for that last term. So i and j are one less than the actual number of terms. This causes the loops to miss the last term of each polynomial. The fix should be to increment i and j after reading each term, including the last one, before the break. However, since we cannot change the structure, the error is in the loop bounds: they should be k<=i and l<=j, but i and j are not updated correctly. Actually, the loops use k<i+1 and l<j+1, which would be correct if i and j were the last index (0-based). But because i and j are not incremented for the last term, they are one less. So the loops miss the last term. The correct fix would be to increment i and j after reading each term, but since we cannot change the code structure, we note the error here.
    {
        for(int l=0;l<j+1;l++) // @@ Error: Same issue as above; loop misses the last term of the second polynomial because j is not incremented for the last term.
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