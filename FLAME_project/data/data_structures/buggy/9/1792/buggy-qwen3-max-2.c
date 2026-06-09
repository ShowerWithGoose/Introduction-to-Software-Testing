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
        *c2 = 0;
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
} // @@ [The recursive combine function only counts forward connections starting from a segment, but does not consider that a longer chain might start earlier and include the current segment. Also, count2 is reset to 0 after each i, but it's initialized to 1 globally, so the first segment in a chain is not counted properly in recursive calls. The initial value of count2 should be 1 for each new chain, but because it's global and reused, the counting logic is flawed. Specifically, count2 starts at 1, then increments for each connected segment, but when combine is called recursively, it continues using the same global count2, which leads to overcounting or incorrect counts when multiple chains are evaluated. Moreover, the algorithm assumes segments are sorted by x1, but a continuous chain may require connecting segments that are not adjacent in the sorted array, and the current approach only checks forward from i, missing backward connections. However, the main issue here is that count2 is a global variable reused across different starting points, and its value is not correctly initialized per chain. In particular, for the test case, the chain 1-2→7-8→9-10 is found (length 2), and 7-78→27-50→75-78 is another chain (length 3), but because count2 is global and not reset to 1 at the start of each top-level combine call, the count becomes incorrect. Actually, looking closer: count2 is set to 0 after each i, but inside combine, it starts from whatever value it had. However, before calling combine, count2 is 0 (because previous iteration set it to 0), then in combine, it does (*c2)++ which makes it 1, then recursively increments. But the initial segment should count as 1, and each connection adds 1, so total length is count2. However, the problem is that combine is only traversing forward in the array (j > i), but after sorting by x1, the segment that continues the chain might appear before i if its x1 is smaller. But in the test case, the correct chain is: (1,2)-(7,8), (7,8)-(9,10) — that's length 2; and (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) — that's length 3. After sorting by x1, the segments are ordered by x1: (1,2,7,8), (7,8,9,10), (7,78,27,50), (27,50,75,78), (75,78,80,67). So the chain starting at (7,78) is at index 2, then connects to index 3, then to index 4. So when i=2, combine will find j=3 (x1=27 == x2=27? Wait: line[2] is (7,78,27,50), so x2=27, y2=50. Then line[3] is (27,50,75,78): x1=27, y1=50 — matches. Then in combine(line,3,n): looks for j>3, finds line[4]: (75,78,80,67): x1=75 == line[3].x2=75, y1=78 == line[3].y2=78 — matches. So (*c2)++ happens twice: once at j=3 (so c2 becomes 2), then in recursive call at j=4 (c2 becomes 3). So total count2=3. Then *c1 becomes 3, and x=line[2].x1=7, y=78. So why output is 2? Because count2 is initialized to 1 globally, and then in main, before combine, count2 is 0 (from previous iteration). Wait: initial values: count1=1, count2=1. Then in main loop:
i=0: call combine -> count2 becomes ... say 2 (for chain of 2 segments). Then if(2>=1) -> c1=2, x=1,y=2. Then c2=0.
i=1: combine -> starts with c2=0, then in combine: finds nothing? because after (7,8,9,10), no segment starts at (9,10). So c2 remains 0? But in combine, it does (*c2)++ only if match. So if no match, c2 stays 0. Then if(0>=2) false. Then c2=0.
i=2: combine -> c2=0 initially. Then in combine: finds j=3 -> c2 becomes 1. Then recursive combine(j=3): finds j=4 -> c2 becomes 2. So total c2=2. Then if(2>=2) -> update c1=2, x=7,y=78. So output is 2 7 78.
But the chain has 3 segments: (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) — that's 3 segments. So count should be 3. The error is that count2 starts at 0, and each connection adds 1, but the initial segment is not counted. The count2 should start at 1 (for the starting segment), and each connected segment adds 1. But in the code, before calling combine, count2 is set to 0 (from previous iteration). Then in combine, when a connection is found, it increments count2. So for a chain of 3 segments, it only increments twice (for the two connections), resulting in count2=2. The fix would be to initialize count2 to 1 before calling combine, but the code sets it to 0 after each iteration, and doesn't set it to 1 before combine. Actually, looking at the code: count2 is a global variable initialized to 1. But in main, after the first iteration, it's set to 0. Then for i=2, before combine, count2 is 0. Then combine is called, and it increments for each connected segment. But the starting segment itself should count as 1, and each additional segment adds 1. So the total number of segments is 1 + number of connections. But the code only counts the connections. Therefore, the initial value of count2 should be 1 for each new chain. However, the code sets count2 to 0 at the end of each loop iteration, and doesn't reset it to 1 before calling combine. So when combine is called, count2 is 0, and it only counts the additional segments beyond the first. Hence, for a chain of 3 segments, it returns 2. The error is that count2 is not initialized to 1 at the start of processing each chain. Specifically, in main, before calling combine, count2 should be set to 1, but instead it's left as 0 from the previous iteration. The line "*c2 = 0;" at the end of the loop causes the next iteration to start with count2=0, but it should start with count2=1 to account for the starting segment.]