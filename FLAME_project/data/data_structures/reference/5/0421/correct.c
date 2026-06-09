#include<stdio.h>
#include<stdlib.h>
struct duo
{
    int xi;
    int pow;
} x1[105],x2[105],x3[10005];

int cmp(const void *a,const void *b)
{
    struct duo *c=(struct duo*)a;
    struct duo *d=(struct duo*)b;
    return d->pow-c->pow;
}

int main()
{
    int a1=0,a2=0,a3=0,i=0,k;
    char c;
    do
    {
        scanf("%d%d%c",&x1[a1].xi,&x1[a1].pow,&c);
        ++a1;
    }
    while(c!='\n');
    do
    {
        scanf("%d%d%c",&x2[a2].xi,& x2[a2].pow,&c);
        ++a2;
    }
    while(c!='\n');
    for(i=0; i<a1; i++)
        for(int j=0; j<a2; j++)
        {
            x3[a3].xi=x1[i].xi*x2[j].xi;
            x3[a3].pow=x1[i].pow+x2[j].pow;
            a3++;
        }
    qsort(x3,a3,sizeof(x3[0]),cmp);
    for(k=0; k<a3; k++)
        if(x3[k+1].pow==x3[k].pow&&x3[k].pow!=0)
        {
            x3[k+1].xi+=x3[k].xi;
            x3[k].xi=0;
        }
    for(i=0; i<a3; i++)
        if(x3[i].xi!=0)
        printf("%d %d ",x3[i].xi,x3[i].pow);
    return 0;
}

