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
            i--; @@ // The decrement happens before checking if the stack is empty. If the stack is empty (i == 0), this makes i = -1, leading to an incorrect "error" message after the fact and potential undefined behavior if used as an index.
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}