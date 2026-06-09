#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node
{  

    int coe;                     
    int pow;
} a[100001],b[100001],p[100001];

int main()
{   int n1=0,n2=0;
	char c=' ';
    while(c!='\n')                                   
    {scanf("%d%d%c",&a[n1].coe,&a[n1].pow,&c);
    n1++;
    }
    c=' ';
    while(c!='\n')                                  
    {scanf("%d%d%c",&b[n2].coe,&b[n2].pow,&c);
    n2++;
    }
    int i,k,j;
for(i=0,k=0;i<n1;i++)
    {
        for(j=0;j<n2;j++,k++)
        {
            p[k].coe=a[i].coe*b[j].coe;
            p[k].pow=a[i].pow+b[j].pow;
        }
    }
    int temp;int x;
	x=k; 
    for(k=0;k<x;k++)
    {
        for(j=k+1;j<x;j++)
        {
            if(p[k].pow<p[j].pow)
            {
                temp=p[k].coe;
                p[k].coe=p[j].coe;
                p[j].coe=temp;
                temp=p[k].pow;
                p[k].pow=p[j].pow;
                p[j].pow=temp;
            }
            else if(p[k].pow==p[j].pow)
            {
                p[k].coe+=p[j].coe;
                p[j].coe=0;
                p[j].pow=0;
            }
        }
    }
    for(k=0;p[k].coe!=0;k++)
    {
        printf("%d %d ",p[k].coe,p[k].pow);
    }
return 0;
}



