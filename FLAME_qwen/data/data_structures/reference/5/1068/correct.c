#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <stdio.h>
typedef struct multi
{
    int num;
    int pow;
}multi;
int cmp3(const void *p1, const void *p2)
{
    multi *x = (multi *)p1;
    multi *y = (multi *)p2;
    if (x->pow != y->pow)
        return (x->pow > y->pow) ? -1 : 1;
};
int main()  
{
    multi a[100];
    multi b[100];
    multi c[100];
    memset(c,0,sizeof(c));
    int i=0,j=0,n,m;
    char ch=0;
    scanf("%d%d",&a[i].num,&a[i].pow);
    ch=getchar();
    while(ch!='\n')
    {
        i++;
        scanf("%d %d",&a[i].num,&a[i].pow);
        ch=getchar();
    }
    n=i+1;
    scanf("%d%d",&b[j].num,&b[j].pow);
    ch=getchar();
    while(ch!='\n') 
    {
        j++;
        scanf("%d %d",&b[j].num,&b[j].pow);
        ch=getchar();
    }
    m=j+1;
    int k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                c[k].num=a[i].num*b[j].num;
                c[k].pow=a[i].pow+b[j].pow;
                k++;
            }
        }
        qsort(c, n*m, sizeof(a[0]), cmp3);
        for(k=0;k<n*m-1;k++)
        {
            int temp=1;
            while(c[k].pow==c[k+temp].pow)
            {
                c[k].num+=c[k+temp].num;
                c[k+temp].num=0;
                temp+=1;
            }
        }
        qsort(c, n*m, sizeof(a[0]), cmp3);
        for(k=0;k<n*m;k++)
            if(c[k].num!=0)
            {
                printf("%d ",c[k].num);
                printf("%d ",c[k].pow);
            }
    return 0;
}
