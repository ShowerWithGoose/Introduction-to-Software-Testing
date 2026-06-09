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
    qsort(d,num3+1,sizeof(node),cmp); // @@ The second argument should be num3, not num3+1, because num3 is the number of elements in array d.
    for(i=0;i<num3;i++)
    {
        if(d[i].pow==d[i+1].pow&&d[i].pow!=0){ // @@ This loop accesses d[i+1] when i = num3-1, which is out of bounds. Also, the condition d[i].pow!=0 incorrectly skips combining terms with exponent 0.
            d[i+1].coe=d[i+1].coe+d[i].coe;
            d[i].coe=0;
        }
    }
    for(i=0;i<num3;i++)
    {
        if(d[i].pow!=0) // @@ This condition incorrectly filters out terms with exponent 0, which should be printed (e.g., constant term).
        {
            printf("%d %d ",d[i].coe,d[i].pow);
        }
    }
    return 0;
}