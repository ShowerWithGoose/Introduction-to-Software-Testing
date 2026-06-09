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
int in(int*stack,int &top,int a){ @@ // C does not support reference parameters (int &top); should be (int *top)
    if(isfull(top)){
        printf("error ");
        return 0;
    }
    stack[++top]=a;
    return 1;
}
int out(int*stack,int &top,int a){ @@ // C does not support reference parameters (int &top); should be (int *top)
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
            in(stack,top,a); @@ // Passing 'top' by value instead of by reference; function expects reference (invalid in C), so modifications to top inside in() won't affect main's top
        }else{//out
            out(stack,top,a); @@ // Same issue: passing 'top' by value; also, 'a' is uninitialized and unused correctly for pop output
        }
    }
    return 0;
}