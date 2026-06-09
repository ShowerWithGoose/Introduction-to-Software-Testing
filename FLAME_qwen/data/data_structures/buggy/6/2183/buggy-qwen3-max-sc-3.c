#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1;
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ [The condition for an empty stack should be `top == -1`, not `top == 0`. This causes pop operations to incorrectly report "error" even when the stack has one element (at index 0).]
}
int main(){
    int stack[111];
    int top = -1;
    int a, b;
    while(scanf("%d",&a)){ // @@ [The loop condition `while(scanf("%d",&a))` only breaks on input failure or EOF if scanf returns 0 or negative. However, scanf returns the number of successfully read items, so it returns 1 on success and continues indefinitely until non-integer input. It should check for `!= EOF` or `== 1` explicitly to match the reference behavior.]
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