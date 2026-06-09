#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct l				
{
    int beginx;
    int beginy;
    int endx;
    int endy;
    int num;					
}l[132];



int cmp(const void *a, const void *b)			
{												
    struct l *c = (l *)a;						
    struct l *d = (l *)b;
    if(c->beginx!=d->beginx) {
		return d->beginx-c->beginx;
	}
    else {
		return d->beginy-c->beginy;
	}
}
int main()
{
    struct l l[132];
    int n,max=0,flag=0;
    scanf("%d",&n);		
    for(int i = 0; i < n; i++)
        scanf("%d%d%d%d",&l[i].beginx,&l[i].beginy,&l[i].endx,&l[i].endy),l[i].num = 1;

    qsort(l,n,sizeof(l[0]),cmp);					


    for(int i = 0; i <= n; i++)
    {
        for(int j = i; j <= n; j++)					
        {											
            if(l[j+1].endx==l[i].beginx&&l[j+1].endy==l[i].beginy)
            {
                l[j+1].num+=l[i].num;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(l[i].num > max){
			max = l[i].num;
			flag = i;
		}
            				
    }
    printf("%d %d %d",max,l[flag].beginx,l[flag].beginy);		
    return 0;
}

