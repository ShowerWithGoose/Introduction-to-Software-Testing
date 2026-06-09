#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int Stack[MAX] = {0};//栈初始化为全0（入栈数字不可能为0，似乎不是十足重要） 
int top = -1;

int main()
{
    int op, data;
    
    scanf("%d", &op);
    while(op != -1){
        if(op == 1){//入栈 
            scanf("%d", &data);
            if(isFull(Stack)){ // @@ Error: isFull function is not declared before use; also, the function is defined after main, so it needs a forward declaration or be moved before main.
                printf("error ");
            }else{
                Stack[++top] = data;
            }
        }
        else{//出栈 
            if(isEmpty(Stack)){ // @@ Error: isEmpty function is not declared before use; same issue as isFull.
                printf("error ");
            }else{
                printf("%d ", Stack[top]); 
                top--;
            }
        }
        scanf("%d", &op);
    }
    
    return 0;
}
/*判断是否满栈*/
int isFull(int Stack[]) // @@ Error: Function defined after main but used in main without prior declaration.
{
    return (top == (MAX - 1));
}
/*判断是否空栈*/ 
int isEmpty(int Stack[]) // @@ Error: Function defined after main but used in main without prior declaration.
{
    return (top == 0); // @@ Error: Logic error - top == 0 means the stack has one element (since top starts at -1), not empty. Should be top == -1.
}