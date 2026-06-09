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
    qsort(gather,n,sizeof(struct line),cmp);
    for (int i=n-1;i>0;i--)
    {
        for (int j=i-1;gather[i].start_x>=gather[j].end_x;j--) // @@ [The loop condition should not use >= because segments only connect if endpoints exactly match; also, the inner loop may access invalid index j < 0]
        {
            if (gather[i].start_x==gather[j].end_x &&gather[i].start_y==gather[j].end_y)
            {
                gather[j].count+=gather[i].count;
            }
        }
    }
    int flag=0;
    int max=gather[0].count;
    for (int i=0;i<n;i++)
    {
        
        if (max<=gather[i].count) // @@ [Using <= may pick a later segment with same count but not the leftmost starting point; problem requires the starting point of the longest chain, and if multiple chains have same length, the one appearing first in input order isn't guaranteed—however, the real issue is that the DP traversal direction and update logic are flawed]
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
    return data1->end_x-data2->end_x; // @@ [Sorting by end_x alone is insufficient; when building chains from right to left, we need to ensure that when processing a segment, all possible next segments (that start where this one ends) have already been processed. Sorting by start_x or using a different DP order would be more appropriate. The current sort order breaks the dependency chain.]
};