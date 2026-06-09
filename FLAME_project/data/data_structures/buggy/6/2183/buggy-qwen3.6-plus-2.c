#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins(int top){
    return top == 99 ? 0 : 1;
}
int ous(int top){
    return top == 0 ? 0 : 1; // @@ The condition for checking if the stack is empty is incorrect. When top is -1 (empty), ous(-1) returns 1 (true, meaning not empty/valid to pop), which leads to accessing invalid memory or incorrect logic. It should check if top < 0 or top == -1 to indicate empty. Specifically, if top is -1, we cannot pop. The current logic: if top==0, returns 0 (false, cannot pop). But if top is -1, it returns 1 (true, can pop), which is wrong.
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
        else if(a == 0 && !ous(top)){ // @@ Due to the bug in ous(), when top is -1, ous(-1) returns 1. So !ous(-1) is 0. This branch is skipped.
            printf("error ");
        }
        else if(a == 0 && ous(top)){ // @@ Due to the bug in ous(), when top is -1, ous(-1) returns 1. This branch is taken. It executes stack[top--], which accesses stack[-1], leading to undefined behavior or incorrect output. In the test case, after pushing 567, top is 0. Pop works correctly there. However, let's re-evaluate. 
            // Wait, let's trace the test case: 1 567 0 -1
            // 1. Read a=1. ins(-1) -> -1==99? No -> 1. True. Scanf b=567. stack[0]=567. top becomes 0.
            // 2. Read a=0. ous(0) -> 0==0? Yes -> 0. !ous(0) is 1. So it enters "else if(a == 0 && !ous(top))". Prints "error ".
            // This is the bug. When top is 0, there IS one element. We SHOULD be able to pop.
            // The function ous(top) returns 0 if top==0. This implies "not ok to pop". But if top is 0, stack[0] exists.
            // Standard stack with top=-1 initial: empty is top==-1. Pop is valid if top >= 0.
            // ous should return 1 if pop is valid (top >= 0), 0 otherwise.
            // Current ous: returns 0 if top==0. Returns 1 if top!=0 (e.g., -1, 1, etc.).
            // If top=0, ous(0)=0. !ous(0)=1. Enters error branch. Wrong.
            // If top=-1, ous(-1)=1. ous(-1)=1. Enters pop branch. Wrong.
            printf("%d ", stack[top--]);
        }
    }

    return 0;
}