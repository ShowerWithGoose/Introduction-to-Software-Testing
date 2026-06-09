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
                    printf("%d ", a.data[a.top--]); // @@ [The pop operation should first decrement the top index, then access the element. Here, it accesses the element at the current top (which is the next free slot) and then decrements, leading to an off-by-one error and incorrect popped values.]
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