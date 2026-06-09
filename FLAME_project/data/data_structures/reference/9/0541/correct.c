#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int cmp(const void *a, const void *b);

typedef struct line   
{
    int stax;
    int stay;
    int endx;
    int endy;
    int tot;    
}line[150];

int main()
{
	int i,j,n;
    struct line line[150];
    scanf("%d",&n);   
	    
    for(i = 0; i < n; i++){
    	scanf("%d%d%d%d",&line[i].stax,&line[i].stay,&line[i].endx,&line[i].endy);
        line[i].tot = 1;
	}

    qsort(line,n,sizeof(line[0]),cmp);     


    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)           
            if(line[i].stax==line[j+1].endx && line[i].stay == line[j+1].endy) line[j+1].tot += line[i].tot;
    }
    
    int max = -1; 
	int flag = 0;
    
    for(i = 0; i < n; i++)
    {
        if(line[i].tot > max)
            max = line[i].tot,flag = i;    
    }
    
    printf("%d %d %d",max,line[flag].stax,line[flag].stay);  
    return 0;
}

int cmp(const void *a, const void *b) 
{            
    struct line *p1 = (line *)a;      
    struct line *p2 = (line *)b;
    if(p1->stax!=p2->stax) return p2->stax - p1->stax;
    else return p2->stay - p1->stay;
}

