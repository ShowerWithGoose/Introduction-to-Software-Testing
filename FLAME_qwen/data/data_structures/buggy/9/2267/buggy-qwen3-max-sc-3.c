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
        for (int j=i-1;gather[i].start_x>=gather[j].end_x;j--) // @@ [The loop condition may cause out-of-bounds access when j becomes negative, leading to undefined behavior. Also, the logic for connecting segments is flawed because it assumes sorted order by end_x but traverses backward incorrectly.]
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
    return data1->end_x-data2->end_x;
}; // @@ [The semicolon after function definition is unnecessary and may cause compilation warnings or errors in some compilers, though many tolerate it. However, combined with other logic errors, this contributes to incorrect behavior.]