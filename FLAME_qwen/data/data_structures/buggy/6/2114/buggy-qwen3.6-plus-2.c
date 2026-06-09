#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int const maximum=100;
int A[maximum]; // @@ In C, 'const' variables are not compile-time constant expressions, so they cannot be used as array dimensions. This causes a compilation error. Use '#define' or 'enum' instead.
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
            printf("error "); // @@ The function 'pop' is declared to return 'int', but this branch does not return a value. Control reaches the end of a non-void function, causing a compilation error.
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