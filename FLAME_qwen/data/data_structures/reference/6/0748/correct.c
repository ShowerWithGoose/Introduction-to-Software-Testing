#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top=-1;
void push(int s[],int n){
    if(Top==MAXSIZE-1)
        printf("Full stack");
    else{
        s[++Top]=n;
    }
}

void pop(int s[],int n){
    if(Top==-1)
        printf("error ");
    else{
        printf("%d ",s[Top--]);
    }
}
int main()
{
    int flag,num;
    int i=0;
    int stack[MAXSIZE];
    while(flag!=-1){
        scanf("%d",&flag);
        if(flag==1){
            scanf("%d",&num);
            push(stack,num);
        }
        else if(flag==0){
            pop(stack,num);
        }
        else if(flag==-1){
            break;
        }
    }
    return 0;
}



