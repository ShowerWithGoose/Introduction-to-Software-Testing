#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdlib.h> 
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
typedef struct line line;
int cmp(const void *p1,const void *p2);
void combine(line line[],int i,int n);

int count1=1,count2=1;
int *c1=&count1,*c2=&count2;
int x=0,y=0; 

int main()
{
    line line[105] = {0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    for(int i=0;i<n;i++)
    {
        combine(line,i,n);
        if((*c2)>=(*c1))
        {
            *c1 = *c2;
            x = line[i].x1;
            y = line[i].y1;
        }
        *c2 = 0; // @@ The counter c2 is reset to 0, but it should be reset to 1 because any single segment constitutes a chain of length 1. Resetting to 0 causes the length calculation to be off by one, or fails to count the starting segment itself in the next iteration properly if logic relies on incrementing from base 1. More critically, the recursive function `combine` increments `c2` for every *connected* segment found. If `c2` starts at 0, and we find 2 connections, `c2` becomes 2. But the total segments are 3 (start + 2 connected). The initial value of `count2` is 1, which is correct for the first run. However, inside the loop, `*c2 = 0` resets it. In the next iteration, `combine` will increment it for each connection. If a segment has no connections, `c2` remains 0. The check `if((*c2)>=(*c1))` will then compare 0 with the previous max. This is incorrect because a single segment has length 1. So `c2` should be reset to 1.
    }
    printf("%d %d %d",*c1,x,y);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    line *v1 = (line*)p1;
    line *v2 = (line*)p2;
    if((v1->x1)>(v2->x1)) return 1;
    else if((v1->x1)<(v2->x1)) return -1;
    else return 0;
}

void combine(line line[],int i,int n)
{
    for(int j=i+1;j<n;j++)
    {
        if((line[j].x1==line[i].x2)&&(line[j].y1==line[i].y2))
        {
            (*c2)++;
            combine(line,j,n);
        }
    }
}