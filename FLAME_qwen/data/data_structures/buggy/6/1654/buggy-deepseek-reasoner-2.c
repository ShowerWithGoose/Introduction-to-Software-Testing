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

int mian(){ // @@ misspelled main function, should be int main()
    int judge=2;
    for(;;){
        scanf("%d",&judge);
        if(judge==-1){
            printf("\n"); // @@ prints newline unnecessarily, should not be present
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