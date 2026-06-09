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
            if (i < 0) // @@ [Error: The pop operation decrements i before checking if the stack is empty. If i is 0, decrementing makes i = -1, and then the condition i < 0 is true, but the element at a[-1] is not accessed. However, the logic is flawed because the pop should check emptiness before decrementing. The correct order is to check if i == 0 first, then if not empty, decrement and output.]
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}