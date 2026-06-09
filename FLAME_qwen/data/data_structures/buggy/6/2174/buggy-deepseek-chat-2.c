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
            i--;
            if (i < 0) // @@ [Error: The pop operation decrements i before checking if the stack is empty. If i is 0, decrementing makes it -1, and then the condition i < 0 catches it, but the value a[-1] is not accessed. However, the logic is flawed because the pop should first check if the stack is empty (i == 0) before decrementing. The correct order is to check i == 0 first, then if not empty, decrement and output. This code outputs "error " but also incorrectly modifies i to -1, which may affect subsequent operations.]
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}