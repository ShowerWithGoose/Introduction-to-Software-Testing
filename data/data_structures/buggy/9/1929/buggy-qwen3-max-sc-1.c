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
    line *gather = malloc(sizeof(line)*n); // @@ [Variable 'n' is used uninitialized. The value of 'n' is indeterminate, leading to undefined behavior when allocating memory and in the loop condition.]
    for (int i=0;i<n;i++){ // @@ [Loop condition uses uninitialized variable 'n', which may cause unpredictable loop behavior or crash.]
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}