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
    struct line data[MAX]; // @@ Compilation error: 'data' is already defined as a typedef name. Using it as a variable name causes a redeclaration conflict. It should be renamed to avoid shadowing the typedef.
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
        data[i].cnt=1;//初始化
    }
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n-1;j++){ // @@ Logical error: The inner loop bound 'j < n-1' incorrectly skips the last element. It should be 'j < n' to iterate through all remaining segments.
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){ // @@ Logical error: The merging logic is flawed. It only increments the count but does not update the starting coordinates (x1, y1) of the continuous segment, and the descending sort order makes this direct comparison incorrect for chaining segments properly.
            
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
    if(c->x1!=d->x1) return d->x1-c->x1;
    else return d->y1-c->y1;
}