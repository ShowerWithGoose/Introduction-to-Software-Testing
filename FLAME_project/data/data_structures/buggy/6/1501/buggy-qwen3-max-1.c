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
    a.top = 0; // @@ [The stack is initialized with top = 0, which implies the first element will be placed at index 0. However, during pop, a.top is decremented after accessing the element, meaning when there's one element (at index 0), a.top is 1 before pop. This leads to off-by-one errors in both push and pop logic. The standard convention is to initialize top = -1 for empty stack.]
    while (scanf("%d", &i) != EOF) {
        if (i == -1)break;
        if (i == 0) {
            if (a.top == 0)
                printf("error ");
            else {
                    printf("%d ", a.data[a.top--]); // @@ [Because top was initialized to 0 and incremented before storing in push, the current top points to the next available slot, not the last used one. So when popping, it should access a.data[a.top - 1], then decrement. As written, it accesses a.data[a.top] which is out of bounds or uninitialized. For example, after pushing 567, a.top becomes 1, and a.data[1] is never set — only a.data[0] is. Then pop prints a.data[1] (garbage, e.g., 256), causing wrong output.]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]); // @@ [This stores the input value at a.data[a.top] and then increments top. But since top starts at 0, the first element goes to index 0, which is correct. However, the inconsistency arises in pop: pop uses a.top as if it points to the current top element, but actually it points to the next free slot. The real issue is that pop does not adjust correctly — it should print a.data[--a.top] instead of a.data[a.top--]. Alternatively, initialize top = -1 and use ++a.top in push and a.data[a.top--] in pop. The current mix causes pop to read from an uninitialized or incorrect index.]
            }
        }
    }
    return 0;
}