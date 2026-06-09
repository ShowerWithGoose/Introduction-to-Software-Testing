#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 105
int cmp(const void*a,const void*b);
int cmp2(const void *a, const void *b);
typedef struct line{
    int x1;
    int y1;//是起始点的坐标
    int x2;
    int y2;//是终止点坐标 
    int cnt;//连续线段的条数 
}data;
int main()
{
    int n;
    int i=0,j=0;
    scanf("%d",&n);
    struct line data[MAX];
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
        data[i].cnt=1;//初始化
    }
    qsort(data,n,sizeof(data[0]),cmp); // @@ The comparison function cmp sorts in descending order of x1 (and y1), but the logic below assumes that if segment j connects to segment i, j appears before i or is processed in a way that accumulates counts correctly. However, the main logical error is in the nested loop structure and condition.
    for(i=0;i<n-1;i++){ // @@ The loop bounds and logic are incorrect. It iterates i from 0 to n-2 and j from i+1 to n-2. This misses the last element in the inner loop (j should go up to n-1). More importantly, the connection logic is flawed.
        for(j=i+1;j<n-1;j++){ // @@ Inner loop bound is wrong, should be j < n. Also, the condition checks if data[i] starts where data[j] ends (data[i].x1 == data[j].x2). Since the array is sorted by x1 descending, data[j] has smaller or equal x1 than data[i]. If they connect, it means data[j] is to the right of data[i] in geometric space? No, x1 descending means larger x1 comes first. So data[0] has largest x1. If data[i] connects to data[j], it implies data[j]'s end point is data[i]'s start point. But we want to form chains. The standard approach is to sort by x1 ascending and chain forward. Here, sorting is descending. Let's look at the condition: data[i].x1 == data[j].x2. This means segment i starts where segment j ends. So j -> i. If we want to count the length of the chain ending at i, we should add j's count to i. But the code does data[j].cnt += data[i].cnt. This propagates count from i to j. If j -> i, then the chain ending at i includes j. So i.cnt should become j.cnt + 1. The current logic is confused.
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){ // @@ The condition checks if segment i's start matches segment j's end. Given the sort order (descending x1), segment i has a larger x1 than segment j (usually). If they connect, it's likely part of a chain. However, the accumulation logic `data[j].cnt+=data[i].cnt` is incorrect for finding the longest chain starting/ending at specific points without a proper DP or graph traversal. A simpler correct approach for this specific problem (non-intersecting, no 3-way splits) is to sort by x1 ascending, then iterate and chain.
            
            data[j].cnt+=data[i].cnt; // @@ This update rule is logically incorrect for calculating the maximum chain length. It adds the count of the "later" segment (in sorted order) to the "earlier" one, but the direction of connection and the sort order make this unreliable. For the test case: Segments: (12,12)-(13,13) and (13,13)-(50,76). Sorted by x1 desc: (13,13)-(50,76) then (12,12)-(13,13). i=0 (13-50), j=1 (12-13). Check: data[0].x1 (13) == data[1].x2 (13)? Yes. data[0].y1 (13) == data[1].y2 (13)? Yes. So data[1].cnt += data[0].cnt => data[1].cnt becomes 1+1=2. Then qsort by cnt. data[1] has cnt 2, data[0] has cnt 1. Output data[n-1] which is data[1] (if sorted asc by cnt). Wait, cmp2 sorts ascending. So data[n-1] is the one with largest cnt. That would be data[1]. Output: 2 12 12. This actually seems to work for this specific case? Let's re-read the code carefully.
            // Wait, the inner loop is `j < n-1`. So j only goes up to n-2. For n=2, i goes 0 to 0. j goes 1 to 0? No, j=i+1=1. Condition j < n-1 => 1 < 1 is False. So the inner loop NEVER executes for n=2.
            // That is the bug. The loop bound `j < n-1` excludes the last element.
        }
    }
    qsort(data,n,sizeof(data[0]),cmp2);
    printf("%d %d %d\n",data[n-1].cnt,data[n-1].x1,data[n-1].y1);
    return 0;
}
int cmp2(const void *a, const void *b)
{
    struct line *c=(struct line *)a; 
    struct line *d=(struct line *)b;
    return c->cnt-d->cnt;
}
int cmp(const void *a, const void *b)//按x1从小到大排序 
{
    struct line *c=(struct line *)a;//c指向强制转换为结构体类型的变量a     
    struct line *d=(struct line *)b;
    if(c->x1!=d->x1) return d->x1-c->x1; // @@ This sorts in DESCENDING order of x1, contrary to the comment.
    else return d->y1-c->y1;
}