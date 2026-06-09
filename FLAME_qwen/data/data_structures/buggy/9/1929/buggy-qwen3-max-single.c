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
    line *gather = malloc(sizeof(line)*n); // @@ [Variable 'n' is uninitialized when used to allocate memory. This leads to undefined behavior because 'n' contains garbage value. The program should first read 'n' from input before using it in malloc.]
    for (int i=0;i<n;i++){
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    return 0;
}