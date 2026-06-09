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
            i--; // @@ The stack pointer is decremented before checking if the stack was empty. If the stack is empty (i==0), i becomes -1. The subsequent check `if (i < 0)` detects the underflow, but the state of `i` is now corrupted (it is -1 instead of 0). In the next valid pop operation, `i--` will make it -2, and accessing `a[i]` (if the error check logic were different or if we relied on `a[i]` for printing in a corrected version) would be out of bounds. More critically, if an error occurs, `i` should remain 0. By decrementing first, we lose the correct top-of-stack index for future operations if we don't restore it. Specifically, after printing "error ", `i` remains -1. The next time a pop occurs, `i` becomes -2. If a push occurs, it writes to `a[-1]` or similar if not handled carefully, but here `i` is just used as a counter. The main issue is that `i` represents the number of elements. If we pop from empty, `i` should stay 0. Here it becomes -1. Then if we push, `a[-1]` is written? No, push checks `i==100`. If `i` is -1, `a[-1]=ch` is undefined behavior/memory corruption. Wait, the push logic is `a[i] = ch; i++`. If `i` is -1, it writes to `a[-1]`. This is a severe bug. The decrement should happen only if the pop is valid.
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}