#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct q        // @@ The struct tag 'q' is defined, but in C, typedef struct q { ... }; creates an alias 'q' only if specified as 'typedef struct q { ... } q;'. Here it defines a type 'struct q', but the identifier 'q' alone is not a type name unless the typedef includes it. However, the main error is below.
{
    int x;
    int y;
    int x1;
    int y1;
    int num;                
} ;


int p(const void *a, const void *b)            //排序规则
{                                                
    struct q *c = (q *)a;                        // @@ Error: 'q' is not recognized as a type name here. It should be 'struct q *' or the typedef should be corrected to 'typedef struct { ... } q;'. Also, casting 'void*' to 'q*' is invalid syntax if 'q' isn't a type. Correct cast is '(struct q *)a'.
    struct q *d = (q *)b;                        // @@ Error: Same as above. 'q' is not a type. Should be '(struct q *)b'.
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