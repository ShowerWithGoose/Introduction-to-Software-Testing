#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxsize 100
void push(int *stack,int a);
int pop(int *stack);
int top=-1;
int main()
{
    int stack[Maxsize];
    int op,num;
    

    while(1)
    {
        scanf("%d",&op);
        if (op==-1)
        break;
        else
        {
             if (op==1)
        {
                scanf("%d",&num);
                if (top==Maxsize-1)
                {
                     printf("error ");
                }
               
               push(stack,num); // @@ [The push operation is executed even when the stack is full, leading to buffer overflow. The function call should be inside an else block.]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [The pop function is called even when the stack is empty, which leads to undefined behavior (accessing invalid memory). This call should only happen if the stack is not empty.]
            printf("%d ",q); // @@ [This prints the popped value even when the stack was empty, which results in printing garbage or incorrect values instead of just "error ".]
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ [This performs the push unconditionally. It should only execute if the stack is not full, but the check is done in main without preventing this call.]
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ [This accesses stack[top] even when top is -1 (empty stack), causing undefined behavior. The function assumes the caller has validated the stack state, but the caller does not prevent this call when empty.]
        top--;
        return a;
    
}