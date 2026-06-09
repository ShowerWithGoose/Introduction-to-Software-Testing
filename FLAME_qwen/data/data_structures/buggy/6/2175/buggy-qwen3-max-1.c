#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#include <stdlib.h>
#include <stdio.h>
#define M 100
int top=-1,stack[100];
int isempty(int top){
    return top==-1;
}
int isfull(int top){
    return top==M-1;//0~M-1
}
int in(int*stack,int &top,int a){ @@ [Using C++ reference syntax 'int &top' in C code causes compilation error; C does not support pass-by-reference using '&' like C++. Should use pointer instead.]
    if(isfull(top)){
        printf("error ");
        return 0;
    }
    stack[++top]=a;
    return 1;
}
int out(int*stack,int &top,int a){ @@ [Same issue: 'int &top' is invalid in C; must use pointer syntax like 'int *top'.]
    if(isempty(top)){
        printf("error ");
        return 0;
    }
    a=stack[top--];
    printf("%d ",a);
    return 1;
}


int main() {
    int op,a;
    while(scanf("%d",&op)){
        if(op==-1){
            break;//TODO
        }
        if(op){//enter
            scanf("%d",&a);
            in(stack,top,a); @@ [Passing 'top' by value instead of by reference (or pointer); modifications inside 'in' won't affect the actual 'top' variable due to incorrect function signature. But primary error is syntax.]
        }else{//out
            out(stack,top,a); @@ [Same issue: passing 'top' by value and function expects reference (invalid in C).]
        }
    }
    return 0;
}