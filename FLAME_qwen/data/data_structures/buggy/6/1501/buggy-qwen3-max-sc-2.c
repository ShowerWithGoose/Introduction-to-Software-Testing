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
                    printf("%d ", a.data[a.top--]); // @@ [The index `a.top` is decremented after access, but since `a.top` starts at 0 and represents the next available position (not the current top element), accessing `a.data[a.top]` when `a.top > 0` actually accesses one past the last valid element. The correct top element is at `a.data[a.top - 1]`.]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]); // @@ [The logic for push is correct in terms of storing data, but because `a.top` is used as the next free index (starting from 0), the maximum number of elements that can be stored is 100 (indices 0 to 99). However, the condition `a.top == 100` correctly prevents overflow. The real issue is in the pop operation indexing, not here. But note: this line itself is logically consistent with the chosen convention.]
            }
        }
    }
    return 0;
}