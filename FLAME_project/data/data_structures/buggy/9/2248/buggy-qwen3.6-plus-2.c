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
} ; // @@ The typedef defines an alias 'q' for the struct, but the struct itself is anonymous or the syntax is slightly off for typical C usage if 'q' is intended to be the tag. However, the main error is below. In C, when using typedef, you usually do `typedef struct Tag { ... } Alias;`. Here `struct q` is not defined as a tag properly accessible as `struct q` later if `q` is just the typedef name. But the critical error is in function `p`.


int p(const void *a, const void *b)            //排序规则
{                                                
    struct q *c = (q *)a; // @@ Error: 'q' is a typedef name, not a struct tag. It should be `struct q *c = (struct q *)a;` if `q` was a struct tag, or `q *c = (q *)a;` if `q` is the typedef. Given the typedef `typedef struct q { ... } ;`, the type name is `struct q` is invalid because the struct has no tag named q accessible in this scope in standard C if defined this way, OR more likely, the user intended `typedef struct { ... } q;` or `struct q { ... };`. Let's look at the declaration: `typedef struct q { ... } ;`. This defines a struct with tag `q` and NO typedef alias. So the type is `struct q`. The cast `(q *)` is incorrect because `q` is not a type name, `struct q` is. Also, the variable declaration `struct q *c` is correct IF `q` is the tag. But the cast `(q *)` fails. It should be `(struct q *)`.
    struct q *d = (q *)b; // @@ Error: Same as above. 'q' is not a type name. It should be `(struct q *)b`.
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