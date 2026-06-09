#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1; // @@ The stack capacity is 100, so the maximum index is 99. However, the condition should be top == 100 to check if the stack is full (since top is the index of the last element, and when top == 99, the stack has 100 elements and is full, so ins should return 0 when top == 99, which is correct. But the problem states maximum capacity of 100, so top ranges from -1 to 99. When top == 99, the stack is full, so ins returns 0, which is correct. No error here.
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ The condition should be top == -1 to check if the stack is empty. When top == -1, the stack is empty, so ous should return 0. Here it returns 0 when top == 0, which is incorrect because top == 0 means there is one element in the stack.
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