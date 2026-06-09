#include<stdio.h>
#include<stdlib.h>
struct line
{
    int a[2];
    int b[2];
    int len;
}l[105];
int cmp1(const void*a,const void*b)
{
    struct line *c=(struct line*)a;
    struct line *d=(struct line*)b;
    return c->a[0]-d->a[0];
}
int cmp2(const void*a,const void*b)
{
    struct line *c=(struct line*)a;
    struct line *d=(struct line*)b;
    return d->len-c->len;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&l[i].a[0],&l[i].b[0],&l[i].a[1],&l[i].b[1]);}
        qsort(l,n,sizeof(l[0]),cmp1);
    for(i=0;i<n;i++)
        for(j=0; j<i; j++)
            if(l[j].a[0]==l[i].a[1]&&l[j].b[0]==l[i].b[1])
            {
                l[j].a[0]=l[i].a[0];
                l[j].b[0]=l[i].b[0];
                l[j].len++;
            }
            else if(l[j].a[1]==l[i].a[0]&&l[j].b[1]==l[i].b[0])
             {
                l[j].a[1]=l[i].a[1];
                l[j].b[1]=l[i].b[1];
                l[j].len++;
            }
qsort(l,n,sizeof(l[0]),cmp2);
 printf("%d %d %d",l[0].len+1,l[0].a[0],l[0].b[0]);
    return 0;
}

