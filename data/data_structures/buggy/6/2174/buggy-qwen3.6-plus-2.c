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
            i--; // @@ [Error: The stack pointer is decremented before checking if the stack is empty. When i is 0, it becomes -1, leading to invalid array access and corrupted state in subsequent operations.]
            if (i < 0) // @@ [Error: The empty stack condition should be checked before decrementing i. It should check if i == 0 instead of i < 0 to properly handle underflow without modifying the pointer.]
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}