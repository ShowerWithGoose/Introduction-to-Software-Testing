#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct NODE{
    int coe;
    int pow;
};
typedef struct NODE node,*phptr;
int cmp(const void*p1,const void*p2){
    phptr p=(phptr)p1;
    phptr q=(phptr)p2;
    if(p->pow>q->pow)
    return -1;
    else if(p->pow==q->pow)
    return 0;
    else
    return 1;
}
node a[100005],b[100005],d[100005];
int main()
{

    int i,j,num1=0,num2=0,num3=0;
    char c=' ';
    while(c!='\n')
    {
        scanf("%d%d%c",&a[num1].coe,&a[num1].pow,&c);
        num1++;
    }
    c=' ';
    while(c!='\n')
    {
        scanf("%d%d%c",&b[num2].coe,&b[num2].pow,&c);
        num2++;
    }
    for(i=0;i<num1;i++)
    {
        for(j=0;j<num2;j++)
        {
            d[num3].coe=a[i].coe*b[j].coe;
            d[num3].pow=a[i].pow+b[j].pow;
            num3++; 
        }
    }
    qsort(d,num3+1,sizeof(node),cmp); // @@ Error: qsort should use num3, not num3+1, because num3 is the count of elements. Using num3+1 sorts one extra garbage element.
    for(i=0;i<num3;i++) // @@ Error: Loop bound should be i<num3-1 to avoid accessing d[i+1] out of bounds when i = num3-1.
    {
        if(d[i].pow==d[i+1].pow&&d[i].pow!=0){ // @@ Error: Condition d[i].pow!=0 is unnecessary and prevents combining like terms with exponent 0. Should simply check equality of powers.
            d[i+1].coe=d[i+1].coe+d[i].coe;
            d[i].coe=0;
        }
    }
    for(i=0;i<num3;i++)
    {
        if(d[i].pow!=0) // @@ Error: Should check d[i].coe != 0 instead of d[i].pow != 0. This condition skips terms with exponent 0, causing the constant term (200 0) to be omitted.
        {
            printf("%d %d ",d[i].coe,d[i].pow);
        }
    }
    return 0;
}