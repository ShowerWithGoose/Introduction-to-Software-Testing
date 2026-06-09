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
    a.top = 0;
    while (scanf("%d", &i) != EOF) {
        if (i == -1)break;
        if (i == 0) {
            if (a.top == 0)
                printf("error ");
            else {
                    printf("%d ", a.data[a.top--]); @@ [The index `a.top` is decremented after access, but since `a.top` starts at 0 and represents the next available position (not the current top element), accessing `a.data[a.top]` when `a.top > 0` actually accesses one past the last valid element. The stack should be implemented such that `a.top` points to the current top element, or the access should use `a.data[a.top - 1]` and then decrement.]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]); @@ [The stack capacity is 100 elements (indices 0 to 99), but this code allows `a.top` to reach 100, which would write to `a.data[100]`, an out-of-bounds access. The condition should be `a.top >= 100` or the max allowed value for `a.top` should be 99. Additionally, the logic of `a.top` as "next available index" is correct, but the pop operation does not align with it.]
            }
        }
    }
    return 0;
}