#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1;
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ [The condition should be `top == -1` to check if the stack is empty, not `top == 0`. When top is 0, there's still one element in the stack.]
}
int main(){
    int stack[111];
    int top = -1;
    int a, b;
    while(scanf("%d",&a)){ // @@ [The loop condition should check for `!= EOF` to properly detect end-of-input; otherwise, it may result in an infinite loop or undefined behavior on input failure.]
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