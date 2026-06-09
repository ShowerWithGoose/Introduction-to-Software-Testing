#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int const maximum=100; @@ // Error: 'maximum' is not a compile-time constant in C; array size must be a constant expression. Use #define or enum instead.
int A[maximum]; @@ // Error: Array size uses non-constant expression, causing compilation error.
int Top;

void initStack(){//初始化栈
    Top=-1;
};

int isEmpty(){//检测栈是不是空的，空则返回1，不空返回0
    return Top==-1;
}

int isFull(){//检测栈是不是满的，满则返回1
    return Top==maximum-1;
}

void push(int A[],int item)//将item加入栈，若栈满输出error
{
    if( isFull() )
        printf("error ");
    else
        A[++Top]=item;
}

int pop(int A[]){//将栈尾出栈，若栈空输出error，成功出栈则输出出栈的内容
    { if(isEmpty())
            printf("error "); @@ // Error: When stack is empty, function prints "error " but does not return a value, leading to undefined behavior. The function should either return a dummy value or be restructured.
        else
            return A[Top--];
    }
}


int main(){
    int a=2,b;
    initStack();

    while(a!=-1){
        scanf("%d",&a);

        if(a==0){
            if(isEmpty()){
                printf("error ");
            }else{
                printf("%d ",A[Top--]);
            }
        }
        if(a==1){
            scanf("%d",&b);
            push(A,b);
        }
    }

    return 0;
}