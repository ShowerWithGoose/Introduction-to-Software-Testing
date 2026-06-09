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
} ; @@ // 缺少类型别名导致空声明，应改为类似 `} Q;` 或直接使用 struct q

int p(const void *a, const void *b)            //排序规则
{                                                
    struct q *c = (q *)a; @@ // 类型转换错误：q 未定义为类型名，应使用 (struct q *)
    struct q *d = (q *)b; @@ // 同上
    if(c->x!=d->x) return d->x - c->x;
    else return d->y - c->y;
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
    }
    printf("%d %d %d", max, q[flag].x, q[flag].y); 
    
    return 0;
}