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
    loca loc[10000]; // @@ [This redeclares 'loc' as a local variable, shadowing the global 'loc'. As a result, the global 'loc' remains uninitialized and unused, while all operations are done on the local array which is not visible outside main. However, since the rest of the code uses this local 'loc', the real issue lies in the logic below, not this shadowing. But note: the global 'loc' is unused.]
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
        for(j=i;j<n-1;j++) // @@ [The inner loop should not be bounded by 'n-1' but by 'n'. Also, the logic of chaining segments is flawed: it only checks if the current segment's START matches another segment's END, but chaining should follow from END to START of next segment. Moreover, it accumulates 'num' incorrectly by adding entire 'num' of j+1 without ensuring continuity beyond immediate connection.]
        {
            if(loc[i].startx ==loc[j+1].lastx &&loc[i].starty ==loc[j+1].lasty ) // @@ [This condition checks if the START of segment i equals the END of segment j+1, implying segment j+1 comes BEFORE segment i. But the problem requires building chains forward: from END of one to START of next. So this direction is reversed. Also, after sorting by start point descending, this approach doesn't correctly propagate chain lengths.]
            {
                loc[i].num +=loc[j+1].num; // @@ [This adds the entire chain length of j+1 to i, but if j+1 itself was already extended, this leads to overcounting or incorrect accumulation because multiple segments might connect to the same predecessor, violating constraint that only one max chain exists—but more importantly, the DP-like update is not done in topological order.]
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