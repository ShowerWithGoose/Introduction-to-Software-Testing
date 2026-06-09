#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct N
{
    int A;                     
    int B;
} a[100000],b[100000],p[100000],q[100000];
char c = ' ';
int c1 = 0,c2= 0;
int C(const void *a, const void*b)            
{
    struct N * c = (struct N *)a;
    struct N * d = (struct N *)b;
    return d->B - c->B;
}
int main()
{
    while(c!='\n')                                 
    {
        scanf("%d%d%c",&a[c1].A,&a[c1].B,&c);
        ++c1;
    }
    c = ' ';
    while(c!='\n')                               
    {
        scanf("%d%d%c",&b[c2].A,&b[c2].B,&c);
        ++c2;
    }
    int i,j,k=0;
    for(i=0; i<c1;i++)                    
        for(j=0;j<c2;j++)
    {
        p[k].A=a[i].A*b[j].A;
        p[k].B=a[i].B+b[j].B;
        k++;
    }
    qsort(p,k,sizeof(p[0]),C);                  
    for(i=0; i<k; i++)
    {
        if(p[i].B==p[i+1].B && p[i].B!=0)       
        {
            p[i+1].A+=p[i].A;
            p[i].A=0;
        }
    }
    for(i=0;i<k;i++)
        if(p[i].A!=0)
        printf("%d %d ",p[i].A,p[i].B);             
    return 0;
}



