#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>

#define MAXSIZE 100

int isFULL();//judge=1
int isEMPTY();//judge=0
void initstack();
void push(int [],int);
int pop(int []);
int gettop(int []);
int stack[MAXSIZE];
int top=-1;

int mian(){ // @@ [Typo: Function name should be "main" to serve as the program entry point. "mian" causes a compilation/linker error.]
    int judge=2;
    for(;;){
        scanf("%d",&judge);
        if(judge==-1){
            printf("\n"); // @@ [Printing a newline here is not required by the problem specification. The expected output format only includes spaces after popped values or "error". This may cause an extra blank line in the output.]
            break;
        }
        else if(judge==0){
            pop(stack);
        }
        else if(judge==1){
            int nitem;
            scanf("%d",&nitem);
            push(stack,nitem);
        }
        else{
            continue;
        }
    }
    return 0;
}

int isFULL(){
    return top==MAXSIZE-1;
}
int isEMPTY(){
    return top==-1;
}
void initstack(){
    top=-1;
}
void push(int stack[],int nitem){
    if(isFULL()){
        printf("error ");
    }
    else{
        stack[++top]=nitem;
    }
}
int pop(int stack[]){
    if(isEMPTY()){
        printf("error ");
        return 0;
    }
    else{
        printf("%d ",stack[top--]);
        return 1;
    }
}
int gettop(int stack[]){
    return stack[top];
}