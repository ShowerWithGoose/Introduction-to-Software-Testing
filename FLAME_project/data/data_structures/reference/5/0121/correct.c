#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    int m;                     
    int n;
} a[100000],b[100000],p[100000],q[10000];

int cmp(const void *a, const void*b)            
{
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return d->n - c->n;
}
int main()
{
	int cnta = 0,cntb= 0;
    char c=' ';
	while( c != '\n')                                   
    {
        scanf("%d%d%c",&a[cnta].m,&a[cnta].n,&c);
        ++cnta;
    }
    c = ' ';
    while( c != '\n')                                   
    {
        scanf("%d%d%c",&b[cntb].m,&b[cntb].n,&c);
        ++cntb;
    }
    int k = 0;
    for(int i = 0; i < cnta; i++)                      
        for(int j = 0; j < cntb; j++)
    {
        p[k].m = a[i].m*b[j].m;
        p[k].n = a[i].n + b[j].n;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp);                     
    for(int i = 0; i < k; i++)
    {
        if(p[i].n!=0&&p[i].n==p[i+1].n)        
        {
            p[i+1].m += p[i].m;
            p[i].m = 0;
        }
    }
    for(int i = 0; i < k; i++){
		if(p[i].m!=0){
			printf("%d %d ",p[i].m,p[i].n); 
		}
		          
	}          
	return 0;
}

