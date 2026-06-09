#include <stdio.h>

#define MAXSIZE 100

int top = -1, stack[MAXSIZE];

void Push(int data){
    if(top + 1 == MAXSIZE){
        printf("error ");
        return;
    }
    stack[++top] = data;
}

void Pop(void){
    if(top == -1){
        printf("error ");
        return;
    }
    printf("%d ", stack[top]);
    top--;
}

int main(){
    int operation, data;

    while(1){
        scanf("%d", &operation);
        if(operation == -1){
            break;
        } else{
            if(operation == 0){
                Pop();
            } else if(operation == 1){
                scanf("%d", &data);
                Push(data);
            } else{
                perror("Something wrong.");
                return 0;
            }
        }
    }

    return 0;
}

