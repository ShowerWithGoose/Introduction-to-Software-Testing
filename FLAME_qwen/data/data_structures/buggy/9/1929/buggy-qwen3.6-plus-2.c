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
    int n; // @@ [Variable 'n' is declared but never initialized or read from input before being used in malloc and the loop condition, causing undefined behavior and compilation errors under strict warning flags]
    line *gather = malloc(sizeof(line)*n);
    for (int i=0;i<n;i++){
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}