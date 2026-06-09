#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct q        
{
    int x;
    int y;
    int x1;
    int y1;
    int num;                
} ; // @@ 错误：typedef声明缺少类型名，导致编译错误。应改为 `} Q;` 或直接 `struct q { ... };`
// 注意：下一行是空行，不需要标记

int p(const void *a, const void *b)            //排序规则
{                                                
    struct q *c = (q *)a; // @@ 错误：`q` 不是类型名，应使用 `struct q *`，否则编译错误
    struct q *d = (q *)b; // @@ 错误：同上
    if(c->x!=d->x) return d->x - c->x; // @@ 错误：排序应为递增（x从小到大），此处递减导致后续连接方向错误
    else return d->y - c->y; // @@ 错误：同上，应为递增
}

int main()
{
    struct q q[132];
    int n;
    scanf("%d",&n);                                    
    int i,j;
    for(i = 0; i < n; i++){ 
        scanf("%d%d%d%d", &q[i].x, &q[i].y, &q[i].x1, &q[i].y1), q[i].num = 1;
    }
     
    qsort(q, n, sizeof(q[0]), p);                


    for(i = 0; i < n-1; i++){
        for(j = i; j < n-1; j++){                
            if( q[i].x==q[j+1].x1 && q[i].y == q[j+1].y1 ){
                q[j+1].num += q[i].num;
            }
        }
    }
    
    int max = -1; int flag = 0;
    for(i = 0; i < n; i++){
        if(q[i].num > max){ 
            max = q[i].num,flag = i;    
        }        
            //找出最大值，并记录坐标
    }
    printf("%d %d %d", max, q[flag].x, q[flag].y); // @@ 错误：输出的是最长链末尾线段的起点，应输出链头起点
        //输出
    
    return 0;
}