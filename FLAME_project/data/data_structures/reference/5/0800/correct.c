#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct A
{
    int xi_a;
    int zhi_a;
} a[50];
struct B
{
    int xi_b;
    int zhi_b;
} b[50];

struct C
{
    int xi_c;
    int zhi_c;
} s[40011];

int cmp(const void *a,const void *b)
{
    struct C *m;
    struct C *n;
    m=(struct C *)a;
    n=(struct C *)b;
    if(m->zhi_c < n->zhi_c) return 1;
    else return -1;
}



int main()
{
    char c;
    int i=0,j=0,f=0;
    int la=0,lb=0;
    while(1)
    {
        scanf("%d %d%c",&a[i].xi_a,&a[i].zhi_a,&c);
        i++;
        la++;
        if(c=='\n')
        {
            i=0;
            break;
        }
    }
    i=0;
    while(1)
    {
        scanf("%d %d%c",&b[i].xi_b,&b[i].zhi_b,&c);
        i++;
        lb++;
        if(c=='\n')
        {
            break;
        }
    }
    f=0;
    int lc=la*lb;
    for(i=0; i<la; i++)
    {
        for(j=0; j<lb; j++)
        {
            int p=a[i].xi_a;
            int q=b[j].xi_b;
            s[f].xi_c=(p*q);
            s[f].zhi_c=(a[i].zhi_a)+(b[j].zhi_b);
            f++;
        }
    }
    qsort(s,lc,sizeof(s[0]),cmp);
    for(i=0; i<lc; i++)
    {
        for(j=i; s[j].zhi_c==s[j+1].zhi_c&&j<lc-1; j++) s[j+1].xi_c=s[j].xi_c+s[j+1].xi_c;
        printf("%d %d ",s[j].xi_c,s[j].zhi_c);
        i=j;
    }
    return 0 ;
}


