#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1;
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ [The condition for an empty stack should be `top == -1`, not `top == 0`. This causes pop operations on a stack with one element (top=0) to be incorrectly allowed, and pop on empty stack (top=-1) to incorrectly trigger "error".]
}
int main(){
    int stack[111];
    int top = -1;
    int a, b;
    while(scanf("%d",&a)){ // @@ [The loop condition should check for `!= EOF` to properly detect end-of-input. Using just `scanf(...)` may lead to infinite loop or undefined behavior when input ends, because `scanf` returns EOF (typically -1) which is non-zero and treated as true.]
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