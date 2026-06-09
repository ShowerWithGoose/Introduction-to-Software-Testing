#include <stdio.h>
#include <stdlib.h>

typedef struct line{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int counter;
} line;

int main()
{
    int n;
    line *gather = malloc(sizeof(line)*n); // @@ [Error: n is uninitialized, leading to undefined behavior. The size of the allocation is unpredictable.]
    for (int i=0;i<n;i++){ // @@ [Error: n is uninitialized, so the loop condition is undefined. The loop may not execute correctly.]
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}