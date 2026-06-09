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
} ; // @@ [Error: Missing struct name after typedef. The typedef should be '} q;' to define the type 'q'. Without it, 'q' is undeclared in the comparison function.]


int p(const void *a, const void *b)            //排序规则
{                                                
    struct q *c = (q *)a; // @@ [Error: 'q' is not a type because the typedef is incomplete. Should be '(struct q *)a' or fix the typedef to '} q;'.]                        
    struct q *d = (q *)b; // @@ [Error: Same issue as above.]
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
            //找出最大值，并记录坐标
    }
    printf("%d %d %d", max, q[flag].x, q[flag].y); 
        //输出
    
    return 0;
}