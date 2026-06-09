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
    int n; // @@ n is uninitialized; no input read for number of segments.
    line *gather = malloc(sizeof(line)*n); // @@ malloc uses uninitialized n, leading to undefined behavior.
    for (int i=0;i<n;i++){ // @@ loop condition uses uninitialized n, causing loop to run an arbitrary number of times.
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y); // @@ reading into uninitialized memory; also missing prior scanf for n.
        gather[i].counter = 1;
    }
    return 0;
}