#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct line
{
    int xi;                    
    int zi;
} m[10000+5],a[10000+5],b[10000+5];

int cmp(const void *a, const void*b);

int main()
{
	char c='a';
	
	int la=0,lb=0;
	
	int i=0,j=0,tot=0;
	
    while(c!='\n'){
    	scanf("%d%d%c",&a[la].xi,&a[la].zi,&c);
    	la++;
	}

    c = 'a';
    while( c != '\n'){
    	scanf("%d%d%c",&b[lb].xi,&b[lb].zi,&c);
    	lb++;
	}
    
    for(i = 0; i < la; i++)                       
        for(j = 0; j < lb; j++)
    {
        m[tot].xi = a[i].xi*b[j].xi;
        m[tot++].zi = a[i].zi + b[j].zi;
    }
    
    qsort(m,tot,sizeof(m[0]),cmp);   
	                  
    for(i = 0; i < tot; i++)
    {
        if(m[i].zi != 0&&m[i].zi == m[i+1].zi)        
        {
            m[i+1].xi += m[i].xi;
            m[i].xi = 0;
        }
    }
    
    for(i = 0; i < tot; i++)
        if(m[i].xi != 0) printf("%d %d ",m[i].xi,m[i].zi);             

    return 0;
}

int cmp(const void *a, const void*b)             
{
    struct line * c = (struct line *)a;
    struct line * d = (struct line *)b;
    if(d->zi > c->zi) return 1;
    if(d->zi < c->zi) return -1;
    return 0;
}

