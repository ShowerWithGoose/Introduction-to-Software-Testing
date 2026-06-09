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
                a[i] = ch; // @@ If i is negative (due to previous pop error), writing to negative index is out-of-bounds and corrupts memory. Should ensure i >= 0 before push (or reset i to 0 after pop error).
                i++;
            }
        } else {
            i--; // @@ Decrement occurs before checking if stack is empty, causing negative index and incorrect state. Should check emptiness first.
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}