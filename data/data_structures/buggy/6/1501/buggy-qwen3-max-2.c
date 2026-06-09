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
                    printf("%d ", a.data[a.top--]); @@ [The index a.top is decremented after access, but since a.top represents the next available position (not the current top element), it should be a.data[--a.top] to correctly access and then decrement. As implemented, it accesses one past the last valid element when popping.]
            }
        }
        if (i == 1) {
            if (a.top == 100)
                printf("error ");
            else {
                    scanf("%d", &a.data[a.top++]);
            }
        }
    }
    return 0;
}