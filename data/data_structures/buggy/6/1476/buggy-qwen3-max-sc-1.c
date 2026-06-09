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
        printf("Error: Stack is full.\n"); // @@ [The problem expects "error " (lowercase, no colon, no newline, and followed by a space), but this prints "Error: Stack is full.\n" which does not match the required output format.]
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ [The problem expects "error " (with a trailing space, not a newline). This outputs "error\n", which fails the expected format. Also, returning -1 as an error indicator conflicts with valid data since -1 could be a legitimate stack element.]
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
            if (item != -1) { // @@ [This check assumes -1 never appears as valid popped data. However, the problem allows pushing any integer except 1, 0, or -1 as operation codes—but note: the pushed integer can be -1! So using -1 as error flag is incorrect.]
                printf("%d ", item);
            }
        } else {
            printf("Invalid operation.\n"); // @@ [The problem does not mention handling invalid operations (i.e., op not in {-1, 0, 1}). According to the problem, input only contains valid operations, but this extra check may cause unexpected output if such input occurs. However, more critically, the problem expects only "error " for underflow/overflow—not this message. But since the test input should only have -1,0,1, this line may never trigger. Still, it's unnecessary and could cause issues if input deviates. However, the main errors are in pop/push output format and error signaling.]
        }
    }

    return 0;
}