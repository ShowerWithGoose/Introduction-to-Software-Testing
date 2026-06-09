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
                    printf("%d ", a.data[a.top--]); // @@ [Error: The stack uses 0-based indexing, but top is initialized to 0 and incremented after push, so top points to the next empty slot. When popping, the correct element is at index top-1, but this code decrements top before accessing, which accesses the wrong element. It should be a.data[--a.top] instead of a.data[a.top--].]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]); // @@ [Error: The stack capacity is 100, but the condition checks a.top == 100, which allows pushing when top is 100, exceeding the array bounds (valid indices 0-99). The correct check should be a.top >= 100 or a.top == 100 before incrementing, but since top is incremented after assignment, the condition should be a.top >= 100 to prevent overflow.]
            }
        }
    }
    return 0;
}