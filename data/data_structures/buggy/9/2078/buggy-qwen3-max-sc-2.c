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
}data; // @@ [This typedef defines 'data' as an alias for 'struct line', but later in main(), 'struct line data[MAX];' redeclares 'data' as a variable, causing a naming conflict and compilation error.]
int main()
{
    int n;
    int i=0,j=0;
    scanf("%d",&n);
    struct line data[MAX]; // @@ [This redefines 'data' as a variable of type 'struct line', conflicting with the typedef above which already defined 'data' as a type alias. This causes a compilation error.]
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
        data[i].cnt=1;//初始化
    }
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n-1;j++){ // @@ [The inner loop condition should be j < n, not j < n-1, otherwise the last element is never checked, leading to incorrect merging of segments. However, this is a logic error, not the cause of the compilation error. The primary issue is the name conflict above.]
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){
            
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
    if(c->x1!=d->x1) return d->x1-c->x1; // @@ [This sorts in descending order by x1 due to 'd->x1 - c->x1', but the comment says ascending. However, this is a logic issue, not a compilation error. The real compilation error stems from the 'data' name conflict.]
    else return d->y1-c->y1;
}