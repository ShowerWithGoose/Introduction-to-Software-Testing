#include "stdio.h"

void push(int stack[], int data, int top) { @@ The parameter 'top' is passed by value, so modifications to it inside this function do not affect the 'top' variable in main. This leads to incorrect stack state management.
    if (top >= 99) {
        printf("error ");
        return;
    }
    top++;
    stack[top] = data;
    return;
}

int pop(int stack[], int top) { @@ The parameter 'top' is passed by value. Although this function only reads 'top', the caller must handle the decrement. More critically, the logic in main for handling the return value and decrementing top is flawed because push didn't update top correctly.
    if (top <= -1) {
        printf("error ");
        return 0;
    }

    return stack[top];
}

int main() {
    int stack[100] = {0};
    int top = -1;
    int op;
    while (scanf("%d", &op) != -1) {
        // 1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。
        if (op == -1) {
            break;
        } else if (op == 1) {
            int data;
            scanf("%d", &data);
            push(stack, data, top); @@ Since push receives top by value and doesn't modify the caller's top, the manual increment below is necessary but insufficient because push itself tried to increment its local copy. The correct approach is to pass top by reference or manage top entirely in main. Here, push fails to update the actual stack top correctly for the next operation.
            top++; @@ This line attempts to compensate for push not updating top, but since push also incremented its local copy (which was discarded), the logic is disjointed. However, the primary error is that push checks the OLD top (passed by value) for overflow, then increments locally. If we remove the increment from push, this line would be correct for updating state, BUT push still needs to know the current top to check bounds and place the element. The fundamental issue is pass-by-value for a state variable that needs to be updated.
        } else {
            int a = pop(stack, top); @@ pop is called with the current top. If stack is empty (top == -1), it prints error and returns 0.
            if (a != 0) { @@ This condition is incorrect. If the popped element is actually 0 (which is a valid integer to push/pop according to general stack rules, though the problem says pushed ints are not 1, 0, -1, wait, problem says "integer (which is not 1, 0, or -1)"). So 0 will never be pushed. However, if pop returns 0 due to error, we print error. But if pop returns a valid non-zero number, we print it. The issue is that pop prints "error " itself. So if it's an error, "error " is printed by pop, and then we check a!=0 (a is 0), so we don't print anything else. This part seems okay for error case. But for valid pop, pop does NOT print the value, it returns it. Then we print it. This logic holds IF 0 is not a valid data element. The problem states pushed integers are not 1, 0, or -1. So 0 is not a valid data element. Thus, returning 0 on error is distinguishable.
                printf("%d ", a);
            }
            top--; @@ This decrements top regardless of whether the pop was successful or an error. If it was an error (stack empty), top is already -1. Decrementing it makes it -2, which breaks subsequent empty checks.
        }
    }
    return 0;
}