#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1;
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ [Logical error: The stack is initialized with top = -1, so it is empty when top == -1, not 0. This causes incorrect empty stack detection and out-of-bounds array access.]
}
int main(){
    int stack[111];
    int top = -1;
    int a, b;
    while(scanf("%d",&a)){ // @@ [Logical error: scanf returns EOF (-1) when input ends, which is non-zero and evaluates to true in C, causing an infinite loop. It should be != EOF or == 1.]
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