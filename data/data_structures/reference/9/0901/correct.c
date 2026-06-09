#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct line
{
    int beginx;
    int beginy;
    int endx;
    int endy;
    int num;				
}line[100];

int cmp(const void *a, const void *b)			
{												
    struct line*c=(line*)a;						
    struct line*d=(line*)b;
    if(c->beginx!=d->beginx) return d->beginx - c->beginx;
    else return d->beginy - c->beginy;
}

int main()
{
	struct line line[100];
    int n,m;
    int max=0;
    scanf("%d",&n);									
    for(int i=0;i<n;i++) scanf("%d%d%d%d",&line[i].beginx,&line[i].beginy,&line[i].endx,&line[i].endy),line[i].num=1;
    qsort(line,n,sizeof(line[0]),cmp);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n-1;j++)			
        {											
            if(line[i].beginx==line[j+1].endx&&line[i].beginy==line[j+1].endy) line[j+1].num+=line[i].num;
        }
    }
    for(int i=0;i<n;i++)
    {
    	if(line[i].num>=max)
    	{
    		max=line[i].num;
    		m=i;
		}
	}
	printf("%d %d %d",max,line[m].beginx,line[m].beginy);
    return 0;
}


