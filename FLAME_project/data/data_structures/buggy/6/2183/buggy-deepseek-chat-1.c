#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1; // @@ The stack capacity is 100, so the maximum index is 99. However, the condition should check if top == 99 (full) to return 0, but the initial top is -1, so the first push should succeed. This logic is correct for a 0-indexed stack with capacity 100, but the problem states maximum capacity of 100, so top should be checked against 99 for full. This is fine.
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ The condition checks if top == 0 to indicate empty, but the initial top is -1, so when the stack is empty, top is -1, not 0. This function incorrectly returns 1 (not empty) when top is -1, causing a pop on an empty stack to not be detected as an error.
}
int main(){
    int stack[111];
    int top = -1;
    int a, b;
    while(scanf("%d",&a)){
        if(a == -1)
            break;       
        else if(a == 1 && ins(top)){
            scanf("%d", &b);
            stack[++top] = b;
        }
        else if(a == 1 && !ins(top)){
            scanf("%d", &b);
            printf("error ");
        }
        else if(a == 0 && !ous(top)){
            printf("error ");
        }
        else if(a == 0 && ous(top)){
            printf("%d ", stack[top--]);
        }
    }

    return 0;
}