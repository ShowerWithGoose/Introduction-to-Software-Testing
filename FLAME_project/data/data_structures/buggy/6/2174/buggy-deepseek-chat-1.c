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
            if (i == 100) {
                printf("error ");
            } else {
                scanf("%d", &ch);
                a[i] = ch;
                i++;
            }
        } else {
            i--; // @@ Error: When p == 0 (pop), the code decrements i before checking if the stack is empty. If the stack is empty (i == 0), decrementing i makes it -1, and then the check `if (i < 0)` prints "error ", but the stack pointer is now corrupted. The correct order is to first check if i == 0, print "error ", and only decrement i if the stack is not empty.
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}