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
        *c2 = 0; // @@ [The recursive function `combine` uses a global counter `c2`, but it is reset to 0 after each call. However, the initial value of `c2` should be 1 (to count the starting segment), but it's being reused without proper initialization before each `combine` call. In fact, `c2` starts at 1 globally, but after the first iteration, it's set to 0 and then incremented in `combine`. This leads to undercounting because the base segment isn't counted properly in subsequent iterations. More critically, the logic assumes that the chain always starts at `line[i]`, but due to sorting only by x1, a segment that should extend backward (i.e., another segment ends at `line[i].x1, line[i].y1`) is ignored. The algorithm only extends forward, missing chains that could start earlier.]
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
} // @@ [The `combine` function only searches forward (j > i) for segments that start where the current segment ends. However, after sorting by x1, it's possible that a segment that continues the chain appears before index `i` in the array (if its x1 is smaller but it connects to an earlier part of the chain). But more importantly, the bigger issue is that the algorithm only builds chains in one direction (forward from a starting segment), and does not consider that the longest chain might require connecting segments both before and after. However, given the problem constraints (no intersections, no three segments share an endpoint), the real issue is that the global variable `c2` is shared across all recursive calls and iterations, leading to incorrect counts when multiple chains are explored. Specifically, `c2` is not initialized to 1 at the start of each new chain exploration—it relies on the global state, which is corrupted by previous iterations. For the test case, the correct chain is (1,2)-(7,8), (7,8)-(9,10) — but wait, actually the expected output is 3 starting at (7,78), which corresponds to: (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67). However, after sorting by x1, the order becomes: (1,2,7,8), (7,8,9,10), (7,78,27,50), (27,50,75,78), (75,78,80,67). When i=2 (segment (7,78,27,50)), combine finds j=3 (27,50,...) and then j=4 (75,78,...), so c2 becomes 3. But because c2 is global and was set to 0 after the previous iteration, and then incremented twice (from 0 to 1 to 2), it ends up as 2, not 3. The root cause is that `c2` should start at 1 for each new chain, but it's being reset to 0 in main after each iteration, and then in `combine` it's incremented for each extension. So for a chain of 3 segments, `c2` becomes 0 -> +1 (first extension) -> +1 (second extension) = 2, missing the initial segment. Thus, the count is off by one. The fix would be to initialize `c2` to 1 before calling `combine`, but the current code sets `c2=0` after the call, and relies on the global initial value of 1, which only works for the first iteration.]