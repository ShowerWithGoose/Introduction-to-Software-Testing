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
    qsort(data,n,sizeof(data[0]),cmp); // @@ The comparison function cmp sorts in descending order of x1 (d->x1 - c->x1), but the logic below assumes that if segment j connects to segment i, j should have been processed or accessible. More critically, the nested loop logic is flawed for chaining.
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n-1;j++){ // @@ The inner loop condition j < n-1 excludes the last element (index n-1) from being checked as a potential successor or predecessor in the chain, causing missed connections. It should be j < n.
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){ // @@ This condition checks if the start of segment i matches the end of segment j. However, since the array is sorted by x1 descending (due to cmp error), or even if ascending, this specific directionality combined with the loop structure doesn't correctly propagate counts through a chain. It only adds count of i to j if i starts where j ends. But typically we want to extend a chain ending at i with a segment starting at i's end. Also, it modifies data[j].cnt based on data[i].cnt, but if data[i] itself was part of a chain, this might work if ordered correctly, but the sorting and loop bounds are wrong.
            
            data[j].cnt+=data[i].cnt;
        }
    }
    }
    qsort(data,n,sizeof(data[0]),cmp2);
    printf("%d %d %d\n",data[n-1].cnt,data[n-1].x1,data[n-1].y1); // @@ Because the sorting and accumulation logic is flawed, the final result is incorrect. Specifically, cmp sorts descending by x1, so the "start" of the logical chain (smallest x1) is at the end of the array. The accumulation loop tries to add counts from earlier indices (larger x1) to later indices (smaller x1) if they connect. However, the loop bound j<n-1 misses the last element. Even if fixed, the logic `data[j].cnt += data[i].cnt` where `data[i]` is the predecessor in space (larger x? No, cmp is descending x1, so index 0 has largest x1). If index 0 has largest x1, it's the end of a segment. If segment at index j (smaller x1) ends where segment at index i (larger x1) starts, that's a valid connection. But the problem states x1 < x2 for each segment. A continuous line has increasing x. So we want to link segment A (end) to segment B (start) where A.x2 == B.x1. Since A.x2 > A.x1 and B.x1 < B.x2, and A.x2 == B.x1, then A.x1 < A.x2 == B.x1 < B.x2. So A comes before B in x-order. If we sort by x1 ascending, A comes before B. We want to add A's count to B. The current code sorts descending. So B (smaller x1) is at higher index. A (larger x1) is at lower index. So i < j means A is at i, B is at j? No, if sorted descending, index 0 is largest x1. So A (larger x1 than B? No, A.x1 < B.x1 is false. A.x2 == B.x1. A.x1 < A.x2. So A.x1 < B.x1. So A has smaller x1. In descending sort, A is at higher index than B. So i > j. The loop i from 0 to n-2, j from i+1 to n-2. i < j. So i has larger x1 than j. So i is "later" in x-space? No, larger x1 means further right. So i is right, j is left. Connection: j ends where i starts? j.x2 == i.x1? The check is `data[i].x1 == data[j].x2`. So i starts where j ends. This is correct direction for chaining j -> i. But we are adding `data[i].cnt` to `data[j].cnt`? No, `data[j].cnt += data[i].cnt`. This adds the count of the successor (i) to the predecessor (j). This is backwards. We want the chain length to accumulate towards the end. Or if we want the start node to hold the total length, we need to propagate differently. But usually, we want the last segment in the chain to hold the total count. Here, it seems to try to accumulate back to the start. But `data[j]` is the one ending at `data[i]`'s start. So `data[j]` is the predecessor. If we add `data[i]`'s count to `data[j]`, `data[j]` now represents the chain starting at j and going through i. This is plausible if we then find the max cnt. However, the loop bound `j < n-1` is definitely wrong as it skips the last element. And `cmp` sorting descending is confusing but might be intentional for this backward accumulation. The primary error causing WA on the sample is likely the loop bound excluding the last segment from participation in connections or being considered for max.
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
    if(c->x1!=d->x1) return d->x1-c->x1; // @@ The comment says "sort by x1 ascending", but the code returns d->x1 - c->x1, which sorts in descending order. This contradicts the comment and likely the intended logic for standard chain building, though the accumulation logic might have been adapted to it. However, combined with the other errors, it contributes to the failure.
    else return d->y1-c->y1;
}