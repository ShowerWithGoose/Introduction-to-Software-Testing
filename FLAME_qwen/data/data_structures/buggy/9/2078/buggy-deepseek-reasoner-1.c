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
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n-1;j++){ // @@ Error: loop condition should be j<n, otherwise the last segment is never considered as a target for merging.
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){ // @@ Error: only checks one direction (i's start matching j's end). Should also check i's end matching j's start. Also, after merging, the chain's start and end coordinates must be updated to reflect the combined chain; currently not done.
            
            data[j].cnt+=data[i].cnt; // @@ Error: does not mark data[i] as merged or update data[j]'s endpoints, leading to incorrect start point identification later.
        }
    }
    }
    qsort(data,n,sizeof(data[0]),cmp2);
    printf("%d %d %d\n",data[n-1].cnt,data[n-1].x1,data[n-1].y1); // @@ Error: after merging, the segment with maximum cnt may not retain the actual starting point of the continuous chain; the starting point should be tracked separately.
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
    if(c->x1!=d->x1) return d->x1-c->x1;
    else return d->y1-c->y1;
}