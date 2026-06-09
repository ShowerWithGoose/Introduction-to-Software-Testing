#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a[100], i = 0;
    int p, ch;
    while (scanf("%d", &p) != EOF) {
        if (p == -1)
            break;
        else if (p == 1) {
            if (i == 100) { // @@ The integer to be pushed must be read from input before checking if the stack is full. Placing the check here causes the program to skip reading the value when the stack is full, leaving it in the buffer to be misinterpreted as the next operation code.
                printf("error ");
            } else {
                scanf("%d", &ch);
                a[i] = ch;
                i++;
            }
        } else {
            i--; // @@ The stack index is decremented before checking if the stack is empty. If i is 0, it becomes -1, corrupting the stack state and potentially causing out-of-bounds access on subsequent operations. The empty check should be performed before decrementing.
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}