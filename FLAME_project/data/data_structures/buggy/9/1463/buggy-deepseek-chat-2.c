#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct location
{
    int startx;
    int starty;
    int lastx;
    int lasty;
    int num;
 } loca;//定义一个类型 struct location，叫loca 
 loca loc[10000];
 


int cmpfuc(const void *a, const void *b)        
{                                                    
    loca *c = (loca *)a;                        
    loca *d = (loca *)b;
    if(c->startx!=d->startx) return d->startx - c->startx;
    else return d->starty - c->starty;
}
 
 
int main()
{
    int i,j;
    loca loc[10000]; // @@ This local declaration shadows the global array 'loc', causing the global array to be unused and all operations to work on an uninitialized local array.
    int n;
    scanf("%d",&n);
    i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&loc[i].startx ,&loc[i].starty ,&loc[i].lastx ,&loc[i].lasty );
        loc[i].num =1;
    }
    qsort(loc,n,sizeof(loc[0]),cmpfuc);//快排，按起始点从大往小排 
    
    for(i=0;i<n-1;i++)//计算所有线段的长度 
    {
        for(j=i;j<n-1;j++)
        {
            if(loc[i].startx ==loc[j+1].lastx &&loc[i].starty ==loc[j+1].lasty ) // @@ The logic for connecting segments is incorrect. It only checks if the start of segment i matches the end of segment j+1, but does not correctly chain segments in order. Additionally, the nested loop structure does not properly accumulate segment counts along a continuous chain.
            {
                loc[i].num +=loc[j+1].num;
             } 
        }
    }
    int max=-1;
    int flag=0;
    i=0;
    for(i=0;i<n;i++)
    {
        if (loc[i].num >max)
        {
            max=loc[i].num ;
            flag=i;
        }
     }
     printf("%d %d %d",max,loc[flag].startx ,loc[flag].starty ); // @@ The output should be the starting point of the longest continuous line, but due to incorrect chaining logic and sorting, the starting point may be wrong. In the given test case, it outputs 13 13 instead of 12 12.
    return 0;
 }