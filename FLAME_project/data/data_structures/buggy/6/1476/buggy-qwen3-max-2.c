#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;
ElemType Stack[MAXSIZE];
int top = -1;

void initStack() {
    top = -1;
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAXSIZE - 1;
}

void push(ElemType item) {
    if (isFull()) {
        printf("Error: Stack is full.\n"); // @@ [The error message format is incorrect. It should print "error " (lowercase, no colon, no newline) to match expected output format.]
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ [The error message ends with a newline '\n', but the expected output requires a space ' ' after "error". This causes formatting mismatch in output.]
        return -1; // 返回一个特殊值表示 pop 失败
    } else {
        return Stack[top--];
    }
}

int main() {
    int Element, item;
    initStack(); // 初始化栈

    while (1) {
        scanf("%d", &Element);
        if (Element == -1) {
            break; // 如果输入为 -1，则退出循环
        }
        if (Element == 1) {
            scanf("%d", &item);
            push(item);
        } else if (Element == 0) {
            item = pop();
            if (item != -1) {
                printf("%d ", item);
            }
        } else {
            printf("Invalid operation.\n"); // @@ [The problem states that input only contains operations 1, 0, -1 and valid integers to push. This case should not occur, but printing this message introduces unexpected output. However, since test input doesn't trigger this, it's not the main cause of WA. But still, per spec, such input shouldn't happen, so this line may be unnecessary but not directly causing the observed error. The primary errors are in push/pop error messages.]
        }
    }

    return 0;
}