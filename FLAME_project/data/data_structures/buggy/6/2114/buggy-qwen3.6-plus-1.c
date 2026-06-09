#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int const maximum=100; // @@ The variable 'maximum' is declared as 'const int', which makes it a variable-length array (VLA) context in some strict C standards or compilers when used for global array size. Global arrays require constant expressions known at compile time. Changing this to '#define maximum 100' or 'enum { maximum = 100 };' would fix the compilation error.
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