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
        *c2 = 0; // @@ The counter c2 is reset to 0 here, but in the combine function, it starts counting from 1 (initialized globally). More importantly, the logic for finding the longest chain is flawed because `combine` uses global state that isn't properly reset or isolated for each starting segment `i`. Specifically, `count2` is initialized to 1 globally, but reset to 0 in the loop. When `combine` is called, it increments `c2`. If a chain of length 3 is found, `c2` becomes 3. However, the recursion in `combine` doesn't correctly accumulate the length of the entire chain relative to the start node `i` in a way that allows simple comparison. The main issue is that `count2` is global and shared. When `combine(line, i, n)` is called, it increments `c2` for every connected segment found recursively. But `c2` was reset to 0 before the call. Inside `combine`, `(*c2)++` happens. So if `i` connects to `j`, `c2` becomes 1. If `j` connects to `k`, `c2` becomes 2. The total segments in the chain starting at `i` would be `1 + c2` (the segment `i` itself plus the extensions). The code compares `*c2` directly with `*c1`. If the chain is `A->B->C`, starting at A: `combine` finds B (`c2`=1), then recursively finds C from B (`c2`=2). The total segments is 3. But `c2` is 2. The code sets `*c1 = 2`. It misses the starting segment itself in the count stored in `c2` or fails to add 1. Actually, looking closer: `count2` is global. `combine` increments it. If we start at `i`, we want the length of the chain starting at `i`. `combine` counts the *additional* segments connected after `i`. So the total length is `1 + *c2`. The code checks `if((*c2)>=(*c1))`. It should be `if((1 + *c2) >= *c1)` and update `*c1 = 1 + *c2`. Also, `c2` needs to be reset properly. Let's look at the test case. Segments: `(75,78)-(80,67)`, `(7,8)-(9,10)`, `(7,78)-(27,50)`, `(1,2)-(7,8)`, `(27,50)-(75,78)`. Sorted by x1: `(1,2)-(7,8)`, `(7,8)-(9,10)`, `(7,78)-(27,50)`, `(27,50)-(75,78)`, `(75,78)-(80,67)`. Chain 1: `(1,2)-(7,8)` connects to `(7,8)-(9,10)`. Length 2. Chain 2: `(7,78)-(27,50)` connects to `(27,50)-(75,78)` which connects to `(75,78)-(80,67)`. Length 3. Start point `(7,78)`. When `i=0` (`1,2-7,8`): `combine` finds `j=1` (`7,8-9,10`). `c2` becomes 1. Recursively `combine(1, n)`. No further connections. `c2` is 1. `*c1` becomes 1 (incorrectly, should be 2). `x=1, y=2`. When `i=2` (`7,78-27,50`): `combine` finds `j=3` (`27,50-75,78`). `c2` becomes 1. Recursively `combine(3, n)`. Finds `j=4` (`75,78-80,67`). `c2` becomes 2. Recursively `combine(4, n)`. No connections. `c2` is 2. `*c1` (currently 1) < 2. `*c1` becomes 2. `x=7, y=78`. The max length recorded is 2, but it should be 3. The error is that `c2` counts the *edges* or *subsequent segments*, not including the starting segment. The total number of segments is `*c2 + 1`. The comparison and assignment ignore the +1.
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