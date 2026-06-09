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
    int n; // @@ [Error: n is uninitialized; it should be read from input before use]
    line *gather = malloc(sizeof(line)*n); // @@ [Error: uses uninitialized n, leading to undefined behavior]
    for (int i=0;i<n;i++){ // @@ [Error: loop uses uninitialized n; also missing input of number of segments]
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}