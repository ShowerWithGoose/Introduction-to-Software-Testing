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
        for(j=i+1;j<n-1;j++){ // @@ [The inner loop should go up to `n`, not `n-1`, to include the last segment. Also, the logic for chaining segments is flawed: it only checks if segment j ends where segment i starts, but chaining should follow forward direction (i.e., current end matches next start), and it doesn't propagate counts correctly across multiple links.]
        if((data[i].x1==data[j].x2)&&(data[i].y1==data[j].y2)){ // @@ [This condition checks if segment i's start matches segment j's end, which is backward chaining. It should check if segment i's end matches segment j's start to form a forward continuous line.]
            
            data[j].cnt+=data[i].cnt;
        }
    }
    }
    qsort(data,n,sizeof(data[0]),cmp2);
    printf("%d %d %d\n",data[n-1].cnt,data[n-1].x1,data[n-1].y1); // @@ [Because of incorrect chaining logic and loop bounds, the cnt values are not computed correctly, leading to wrong maximum count and starting point.]
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
    if(c->x1!=d->x1) return d->x1-c->x1; // @@ [This sorts in descending order by x1, but the problem requires processing segments in increasing x1 order to build chains forward. Should return c->x1 - d->x1 for ascending order.]
    else return d->y1-c->y1; // @@ [Similarly, this sorts y1 in descending order when x1 is equal, which is unnecessary and may disrupt correct chaining.]
}