#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int co;                     
    int exp;
}poly;
poly a[20000],b[20000],p[20000],q[20000];
int rank(const void *a, const void*b)            
{
    poly *p=(poly*)a,*q=(poly*)b;
    if(p->exp>q->exp)return -1;
    if(p->exp<q->exp)return 1;
    return 0;
}
int main()
{   
    char c=' ';
    int num1=0,num2=0,i,j,k=0;
    while(c!= '\n'){                                   
        scanf("%d%d%c",&a[num1].co,&a[num1].exp,&c);
        num1++;
    }
    c = ' ';
    while( c != '\n'){                                  
        scanf("%d%d%c",&b[num2].co,&b[num2].exp,&c);
        num2++;
    }
    for(i=0;i<num1;i++){                       
        for(j=0;j<num2;j++)
        {
           p[k].co=a[i].co*b[j].co;
           p[k].exp=a[i].exp+b[j].exp;
           k++;
        }
    }
    qsort(p,k,sizeof(p[0]),rank);                     
    for(i=0;i<k;i++)
    {
        if(p[i].exp==p[i+1].exp&&p[i].exp!=0)        
        {
            p[i+1].co += p[i].co;
            p[i].co = 0;
        }
    }
    for(i=0;i<k;i++){
        if(p[i].co!=0)
        printf("%d %d ",p[i].co,p[i].exp);               
    }
    return 0;
}

