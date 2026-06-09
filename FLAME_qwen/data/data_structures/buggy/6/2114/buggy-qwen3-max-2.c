#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int const maximum=100;
int A[maximum];
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
            printf("error ");
        else
            return A[Top--];
    }
} // @@ [The function pop is declared to return an int, but in the error case (isEmpty), it prints "error " and does not return a value, leading to undefined behavior. However, this is not the primary cause of the observed compilation error.]

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
} // @@ [The program does not include a check to break out of the loop immediately after reading -1. As a result, when a == -1, the loop body still executes and may process -1 as an invalid operation. However, the actual reported error is "gcc: not found", which is a system/environment issue, not a code bug. But since the problem states to find errors in the program logic based on test failure, the real logical error is that after reading -1, the loop condition is checked only at the start of the next iteration. More critically, the pop function is defined but never used; instead, popping is done manually in main(), making the pop function redundant and inconsistent with the manual pop logic. Also, the pop function has a syntax anomaly with an extra opening brace '{' right after the function signature, which causes a compilation error.]