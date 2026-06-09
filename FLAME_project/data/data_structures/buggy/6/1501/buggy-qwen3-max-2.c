#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct stack {
    int top;
    int data[100];
}stack;
int main() {
    int i;
    stack a;
    a.top = 0; // @@ [The stack should be initialized with top = -1 to indicate an empty stack. Using top = 0 means the first element is placed at index 0, but then during pop, a.top-- leads to incorrect indexing and underflow behavior.]
    while (scanf("%d", &i) != EOF) {
        if (i == -1)break;
        if (i == 0) {
            if (a.top == 0)
                printf("error ");
            else {
                    printf("%d ", a.data[a.top--]); // @@ [Because top was initialized to 0 and incremented before storing (in push), the current top points to the next available slot, not the last valid element. So on pop, it should access a.data[--a.top] or adjust initialization. As written, it reads from a.data[0] when top=1, but after pop sets top=0, which is correct only if push used post-increment. However, combined with initial top=0, this causes off-by-one errors. Specifically, after pushing one item, top becomes 1, so pop prints a.data[1], which is uninitialized — leading to undefined behavior like outputting 256 instead of 567.]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]); // @@ [This uses post-increment: stores at current top, then increments. But since top starts at 0, the first element goes to index 0, and top becomes 1. Then on pop, a.data[a.top--] accesses a.data[1], which is out of bounds (uninitialized). The logic assumes top points to the next free slot, but pop treats it as pointing to the current top element. This inconsistency causes reading garbage values.]
            }
        }
    }
    return 0;
}