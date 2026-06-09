#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct duo
{
    int xi;
    int ci;
    int flag;
}a[12315],b[12315],c[12315];

int cmpfuc(const void *a,const void *b)
{
    struct duo*c=(struct duo*)a;
    struct duo*d=(struct duo*)b;
    return d->ci - c->ci;
}

int main ()
{
    int i=0,j=0,k=0;
    char s=' ';
    while(s != '\n')
    {
        scanf("%d%d%c",&a[i].xi,&a[i].ci,&s);
        i++;
    }
    s=' ';
    while(s != '\n')
    {
        scanf("%d%d%c",&b[j].xi,&b[j].ci,&s);
        j++;
    }
    for(int p=0;p<i;p++)
    {
        for(int q=0;q<j;q++)
        {
            c[k].xi=(a[p].xi)*(b[q].xi);
            c[k].ci=a[p].ci+b[q].ci;
            c[k].flag=1;;
            k++;
        }
    }
    qsort(c,k,sizeof(c[0]),cmpfuc);
    for(int m=0;m<k;m++)
    {
        if(c[m].ci==c[m+1].ci && c[m].ci!=0)
        {
            c[m+1].xi += c[m].xi;
            c[m].flag=0;
        }
    }
    for(int n=0;n<k;n++)
    {
        if (c[n].flag != 0)
        {
            printf("%d %d ",c[n].xi,c[n].ci);
        }
    }
    return 0;
}

