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
    qsort(data,n,sizeof(data[0]),cmp); // @@ [The sorting order in cmp is descending (d->x1 - c->x1), but we need ascending order by x1 to build chains from left to right. This causes incorrect chaining.]
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n-1;j++){ // @@ [The inner loop should go up to j < n, not j < n-1, so the last segment is considered. Also, the logic only checks if data[j] connects backward to data[i], but chaining should propagate forward: if a segment ends where another starts, the latter should inherit the count. The current double loop does not correctly simulate chain propagation.]
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){ // @@ [This condition checks if the start of segment i matches the end of segment j, which is backwards. It should check if the end of segment i matches the start of segment j: (data[i].x2 == data[j].x1 && data[i].y2 == data[j].y1).]
            
            data[j].cnt+=data[i].cnt;
        }
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
    if(c->x1!=d->x1) return d->x1-c->x1; // @@ [This returns descending order by x1, contradicting the comment and the problem's requirement to process segments from left (smaller x) to right (larger x). Should be c->x1 - d->x1 for ascending order.]
    else return d->y1-c->y1; // @@ [Similarly, this sorts y1 in descending order when x1 is equal, which is unnecessary and may disrupt correct chaining. However, the main issue is the x1 order.]
}