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
    line *gather = malloc(sizeof(line)*n); // @@ [Using uninitialized variable 'n' to allocate memory leads to undefined behavior; 'n' must be read from input before allocation]
    for (int i=0;i<n;i++){ // @@ [Loop runs with uninitialized 'n', which is undefined behavior; also, the loop should process input after reading 'n']
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}