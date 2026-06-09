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
    line *gather = malloc(sizeof(line)*n); // @@ [Error: n is uninitialized, so malloc uses garbage value; also the program does not read n from input, so it cannot process the test case correctly]
    for (int i=0;i<n;i++){ // @@ [Error: n is uninitialized, loop may not execute or cause undefined behavior]
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}