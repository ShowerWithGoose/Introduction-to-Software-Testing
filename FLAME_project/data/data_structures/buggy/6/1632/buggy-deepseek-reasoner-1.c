#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){ // @@ [Error: The stack full check should be performed before incrementing top. Here top is already incremented, so this condition never detects full when top reaches max-1, and may write out of bounds when top becomes max.]
        printf("error ");
        
    }else{
    
        stack[top]=number;
        
    }
        
}
void pop(int stack[],int top){
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
            top++; // @@ [Error: top should only be incremented if the push is possible (stack not full). Incrementing before checking leads to out-of-bounds access when stack is already full.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Error: top should only be decremented if the pop was successful (stack not empty). Decrementing after an empty pop corrupts the stack index.]
        }
    }
    return 0;
}