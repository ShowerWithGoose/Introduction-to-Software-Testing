#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int a;                     
    int x;
} a[10005],b[10005],p[10005];

int cnta = 0,cntb= 0;
char c = ' ';
int cmpfuc(const void *a, const void*b)             
{
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return d->x - c->x;
}
int main()
{
	int i=0,j=0,k=0;
    while( c != '\n')                                   
    {
        scanf("%d%d%c",&a[cnta].a,&a[cnta].x,&c);
        cnta++;
    }
    c = ' ';
    while( c != '\n')                                   
    {
        scanf("%d%d%c",&b[cntb].a,&b[cntb].x,&c);
        cntb++;
    }
    for(i=0;i<cnta;i++)
    {
    	for(j=0;j<cntb;j++)
    	{
    		p[k].a=a[i].a*b[j].a;p[k].x=a[i].x+b[j].x;k++;
		}
	}
	qsort(p,k,sizeof(p[0]),cmpfuc);
    for(i = 0; i < k; i++)
    {
        if(p[i].x == p[i+1].x && p[i].x!= 0)   
        {
            p[i+1].a += p[i].a;
            p[i].a= 0;
        }
    }
    for(i = 0; i < k; i++)
        if(p[i].a != 0)
        printf("%d %d ",p[i].a,p[i].x);

	return 0;
}



