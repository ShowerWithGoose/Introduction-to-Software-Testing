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
    loca loc[10000]; // @@ [This redeclaration of 'loc' shadows the global 'loc', causing all operations to be done on a local uninitialized array instead of the one filled with input data.]
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
        for(j=i;j<n-1;j++) // @@ [The inner loop logic is flawed: it tries to chain segments by checking if the current segment's start matches a later segment's end, but chaining should follow from end to next start, not start to previous end. Also, it doesn't correctly propagate chain lengths.]
        {
            if(loc[i].startx ==loc[j+1].lastx &&loc[i].starty ==loc[j+1].lasty )
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
     printf("%d %d %d",max,loc[flag].startx ,loc[flag].starty ); 
    return 0;
 }