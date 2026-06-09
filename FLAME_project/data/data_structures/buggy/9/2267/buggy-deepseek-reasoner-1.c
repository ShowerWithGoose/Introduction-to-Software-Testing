#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int count;
};
int cmp(const void*,const void*);
int main()
{
    int n;
    scanf("%d",&n);
    struct line *gather=malloc(sizeof(struct line)*n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].count=1;
    }
    qsort(gather,n,sizeof(struct line),cmp); // @@ Sorting by end_x only is incorrect; should sort by start_x then end_x to properly build chains.
    for (int i=n-1;i>0;i--)
    {
        for (int j=i-1;gather[i].start_x>=gather[j].end_x;j--) // @@ The loop condition is wrong: should be j>=0 && gather[i].start_x == gather[j].end_x. The current condition can skip valid predecessors or access out-of-bounds when j becomes -1. Also it only checks a contiguous block, not all possible matches.
        {
            if (gather[i].start_x==gather[j].end_x &&gather[i].start_y==gather[j].end_y)
            {
                gather[j].count+=gather[i].count; // @@ After finding a match, the loop should break to avoid multiple additions (though constraints prevent multiple matches, correctness requires breaking). Also, the algorithm does not ensure the count propagation follows the correct chain order.
            }
        }
    }
    int flag=0;
    int max=gather[0].count;
    for (int i=0;i<n;i++)
    {
        
        if (max<=gather[i].count)
        {
            max=gather[i].count;
            flag=i;
        }
    }
    printf("%d %d %d",max,gather[flag].start_x,gather[flag].start_y);
    
    
    
    free (gather);
    gather=NULL;
    return 0;
}

int cmp(const void*a,const void*b)
{
    struct line *data1=(struct line*)a;
    struct line *data2=(struct line*)b;
    return data1->end_x-data2->end_x; // @@ Comparator sorts only by end_x; should sort by start_x and then end_x to ensure segments are ordered by increasing start_x for chain construction.
};