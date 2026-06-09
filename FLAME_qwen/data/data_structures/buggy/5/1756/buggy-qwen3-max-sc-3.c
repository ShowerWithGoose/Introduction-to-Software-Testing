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
    for(int k=0;k<i+1;k++) // @@ [Loop bound error: should be k <= i (or k < i+1 is okay), but i was not incremented after last successful read, so sn1[i] is valid; however, the real issue is that i and j are not incremented after the last term before break, so the loop runs one extra time with uninitialized data. The correct logic should increment i/j BEFORE checking newline, or adjust bounds accordingly.]
    {
        for(int l=0;l<j+1;l++) // @@ [Same as above: j is not incremented after reading the last term, so sn2[j] is valid, but the loop includes an extra uninitialized term if input parsing logic is flawed.]
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
                for(int l=k;l>-1;l--) // @@ [Loop condition l > -1 causes out-of-bounds access when l becomes -1; should be l >= 0. Also, this inner loop logic for merging terms is unnecessarily complex and buggy.]
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