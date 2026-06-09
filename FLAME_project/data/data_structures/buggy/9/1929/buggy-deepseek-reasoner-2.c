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
    int n; // @@ [n is uninitialized; should read the number of segments first]
    line *gather = malloc(sizeof(line)*n); // @@ [n is uninitialized, causing malloc with undefined size; should allocate after reading n]
    for (int i=0;i<n;i++){ // @@ [loop uses uninitialized n as bound; undefined behavior]
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}