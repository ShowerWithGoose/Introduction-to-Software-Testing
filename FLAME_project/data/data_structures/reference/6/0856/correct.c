#include <stdio.h>

int in(int stack[], int top) {
    int i;
    scanf("%d", &i);
    if (top == 100) {
        printf("error ");
        return 0;
    } else {
        stack[top] = i;
        return 1;
    }
}

int out(int stack[], int top) {
    if (top == 0) {
        printf("error ");
        return 0;
    } else {
        printf("%d ", stack[top - 1]);
        stack[top - 1] = 0;
        return 1;
    }
}

int main() {
    int stack[100], i, top = 0;
    while (1) {
        scanf("%d", &i);
        if (i == -1)
            break;
        else if (i == 1)
            top += in(stack, top);
        else if (i == 0)
            top -= out(stack, top);
    }
    return 0;
}
