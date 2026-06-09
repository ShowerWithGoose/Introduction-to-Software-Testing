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
                    printf("%d ", a.data[a.top--]); // @@ [Error: The stack uses 0-based indexing, but top is initialized to 0 and incremented after push, so top points to the next empty slot. When popping, top should be decremented first before accessing the element, i.e., a.data[--a.top]. The current code accesses a.data[a.top] and then decrements, which accesses an uninitialized slot.]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]); // @@ [Error: The stack capacity is 100, but the condition checks a.top == 100, which allows pushing when top is 100, causing an out-of-bounds write. The correct check should be a.top >= 100 or a.top == 100 before incrementing, but since top is incremented after assignment, the condition should be a.top >= 100 to prevent overflow.]
            }
        }
    }
    return 0;
}