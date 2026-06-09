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
        i++; // @@ [Loop condition causes one less term to be read: the last term before '\n' is not counted because `i++` happens only when newline is not encountered. Thus, the first polynomial misses its last term.]
    }
    while(1)
    {
        scanf("%d%d",&sn2[j].c,&sn2[j].d);
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: the last term of the second polynomial is not counted due to increment happening only on non-newline.]
    }
    int op=0;
    for(int k=0;k<i+1;k++) // @@ [Loop bound should be `k <= i` or `k < i+1` only if `i` correctly counts all terms. But since `i` is one less than actual number of terms, this leads to reading uninitialized/sn1[i] which is garbage.]
    {
        for(int l=0;l<j+1;l++) // @@ [Same issue: `j` is undercounted, so `j+1` accesses sn2[j] which was never properly read.]
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
                for(int l=k;l>-1;l--) // @@ [Loop condition `l > -1` may access sn[-1] when l becomes -1, causing undefined behavior. Should be `l >= 0`.]
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