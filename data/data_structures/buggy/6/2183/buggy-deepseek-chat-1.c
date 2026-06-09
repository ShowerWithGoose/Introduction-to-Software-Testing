#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1;
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ The condition should be top == -1 to check if the stack is empty, not top == 0.
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