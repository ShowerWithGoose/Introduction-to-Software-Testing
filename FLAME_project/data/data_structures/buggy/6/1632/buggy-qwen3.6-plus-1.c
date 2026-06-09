#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ @@ The parameter 'top' is passed by value, so modifying it or using it to update the global state incorrectly. Also, the global 'top' is incremented in main before calling push, but push receives the old value if not careful, or rather, the logic of incrementing top in main and then passing it is flawed because push doesn't update the global top correctly if it were to use its local parameter. More critically, the global variable 'top' is being managed in main, but the functions push and pop take 'top' as an argument by value, meaning they cannot modify the global 'top' directly through the parameter. However, the code uses the global 'top' in main. The real issue is that push and pop are using the passed 'top' value which is a copy. In push, stack[top]=number uses the passed top. In main, top is incremented before push. So if top was -1, it becomes 0. push gets 0. stack[0]=number. This part seems okay for push IF top is managed correctly. BUT, look at pop.
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number;
        
    }
        
}
void pop(int stack[],int top){ @@ Similar to push, 'top' is passed by value. The function checks the passed top. In main, top is decremented AFTER pop is called. So if top is 0, pop is called with 0. It prints stack[0]. Then main does top-- making it -1. This logic for indices seems reversed or confused compared to standard stack implementations where top points to the current element. Let's trace: Initial top=-1. Push 5: main does top++ (top=0). push(stack, 0, 5). stack[0]=5. Correct. Pop: main calls pop(stack, 0). pop prints stack[0] (5). Then main does top-- (top=-1). Correct so far. Next Pop: main calls pop(stack, -1). pop checks if top==-1. Prints "error ". Then main does top-- (top=-2). ERROR HERE. The global top becomes -2. Next Push 8: main does top++ (top=-1). push(stack, -1, 8). stack[-1]=8. Out of bounds/undefined behavior. The management of 'top' in main combined with passing it by value to functions that don't update the global state (though they don't need to if main does it) is fragile. The specific error is that when pop fails (empty stack), main still decrements top, corrupting the stack index.
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]);
    
    
    }
    
}
int main(){
    int number;int stack[max]={0};
    while(scanf("%d",&number)){
        if(number==-1){
        break;
        }
        else if(number==1){
            scanf("%d",&number);
            top++;
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; @@ This line executes regardless of whether the pop was successful or an error occurred. If the stack was empty, pop prints "error ", but top is still decremented, leading to incorrect state for subsequent operations.
        }
    }
    return 0;
}