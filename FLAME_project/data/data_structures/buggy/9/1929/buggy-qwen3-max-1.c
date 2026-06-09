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
    line *gather = malloc(sizeof(line)*n); // @@ [Using uninitialized variable 'n' to allocate memory; 'n' is read after this allocation, leading to undefined behavior and likely memory corruption or crash]
    for (int i=0;i<n;i++){ // @@ [Loop uses uninitialized 'n'; even if allocation were fixed, 'n' hasn't been read from input yet]
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}