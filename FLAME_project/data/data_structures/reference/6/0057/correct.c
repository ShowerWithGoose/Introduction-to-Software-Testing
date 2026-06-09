#include <stdio.h>
void main()
{
    int stack[120]={}, x, i = 0;
    while (scanf ("%d", &x)) {
        if (x == -1) break;
        if (x == 0) {
            if (i == 0) printf ("error ");
            else {
                printf ("%d ", stack[i-1]);
                i--;
            }
        }
        else {
            if (i == 100) {
                printf ("error ");
                continue;
            }
            scanf ("%d", &stack[i]);
            i++;
        }
    }
    return ;
}
