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
               
               push(stack,num); // @@ [Push is executed even when the stack is full, leading to buffer overflow. The function call should be inside an else block.]
        }
        else if (op==0)
        {
            if (top==-1)
            {
                printf("error ");
            }
            int q;
            q=pop(stack); // @@ [Pop is executed even when the stack is empty, which leads to undefined behavior (accessing invalid memory). This line should only execute if the stack is not empty.]
            printf("%d ",q); // @@ [This prints a garbage value or causes undefined behavior when pop was called on an empty stack. It should only print if pop was valid.]
        }  
        }
    }
    
    
    return 0;
}

void push(int *stack,int a)
{
    stack[++top]=a; // @@ [This assumes there's space in the stack, but the check for fullness is done in main and doesn't prevent this call. Should check isfull() here or ensure it's only called when not full.]
    
}
int pop(int *stack)
{
    
    
        int a=stack[top]; // @@ [If called when stack is empty (top == -1), this accesses stack[-1], which is invalid and causes undefined behavior.]
        top--;
        return a;
    
}