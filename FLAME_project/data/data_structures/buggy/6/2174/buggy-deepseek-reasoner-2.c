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
                printf("error "); // @@ When stack is full, the subsequent integer value in the input is not read, causing the next scanf to misinterpret it as an operation.
            } else {
                scanf("%d", &ch);
                a[i] = ch;
                i++;
            }
        } else {
            i--; // @@ Decrementing i before checking emptiness causes i to become -1 on an empty stack, corrupting the stack index and leading to out‑of‑bounds writes on subsequent pushes.
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}