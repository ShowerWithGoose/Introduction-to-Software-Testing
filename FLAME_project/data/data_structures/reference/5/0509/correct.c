#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct multi
{
    int coe;
    int index;
};
int cmp(const void*p1,const void*p2);
int main()
{
    struct multi a[1005];
    struct multi b[1005];
    struct multi c[1005];
    int i,j,numa=0,numb=0,numc=0,temp1,temp2;
    char ch;
    do
    {
        scanf("%d%d%c",&a[numa].coe,&a[numa].index,&ch);
        numa++;
    }
    while(ch!='\n');
    do
    {
        scanf("%d%d%c",&b[numb].coe,&b[numb].index,&ch);
        numb++;
    }
    while(ch!='\n');
    for(i=0; i<numa; i++)
    {
        for(j=0; j<numb; j++)
        {
            c[numc].coe=a[i].coe*b[j].coe;
            c[numc].index=a[i].index+b[j].index;
            numc++;
        }
    }
    for(i=0; i<numc; i++)
    {
        for(j=i+1; j<numc; j++)
        {
            if(c[i].index==c[j].index&&c[i].index!=0)
            {
                c[i].coe+=c[j].coe;
                c[j].coe=0;
            }
        }
    }
    /*for(i=0; i<numc; i++)
    {
        for(j=i+1; j<numc; j++)
        {
            if(c[i].index<c[j].index)
            {
                temp1=c[i].index;
                c[i].index=c[j].index;
                c[j].index=temp1;
                temp2=c[i].coe;
                c[i].coe=c[j].coe;
                c[j].coe=temp2;
            }
        }
    }*/
    qsort(c,numc,sizeof(struct multi),cmp);
    for(i=0; i<numc; i++)
    {
        if(c[i].coe!=0)
            printf("%d %d ",c[i].coe,c[i].index);
    }
    return 0;
}
int cmp(const void*p1,const void*p2)
{
    struct multi *a=(struct multi*)p1;
    struct multi *b=(struct multi*)p2;
    return b->index-a->index;
}

