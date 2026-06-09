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
    for(int k=0;k<i+1;k++) // @@ Declaring loop variable 'k' inside 'for' is a C99 feature and may cause compilation errors in C89/C90 environments. Move declaration to the beginning of the block.
    {
        for(int l=0;l<j+1;l++) // @@ Declaring loop variable 'l' inside 'for' is a C99 feature and may cause compilation errors in C89/C90 environments. Move declaration to the beginning of the block.
        {
            sn[op].c=sn1[k].c*sn2[l].c;
            sn[op].d=sn1[k].d+sn2[l].d;
            op++;
        }
    }
    qsort(sn,op,sizeof(struct node),cmp);
    for(int k=0;k<op;k++) // @@ Declaring loop variable 'k' inside 'for' is a C99 feature and may cause compilation errors in C89/C90 environments. Move declaration to the beginning of the block.
    {
        if(k!=0&&sn[k].d==sn[k-1].d)
        {
            //printf("%d\n",k);
            if(sn[k-1].c==0)
            {
                int flag=0;
                for(int l=k;l>-1;l--) // @@ Declaring loop variable 'l' inside 'for' is a C99 feature and may cause compilation errors in C89/C90 environments. Move declaration to the beginning of the block.
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
    for(int k=0;k<op;k++) // @@ Declaring loop variable 'k' inside 'for' is a C99 feature and may cause compilation errors in C89/C90 environments. Move declaration to the beginning of the block.
    {
        if(sn[k].c!=0)
        printf("%d %d ",sn[k].c,sn[k].d);
    }
    return 0;
}