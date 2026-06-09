#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MaxSize 100
typedef struct node{
    int data[MaxSize];
    int top;
}SqStack;
int INITIALS(SqStack *S)
{
    S->top=-1;
    return 1;
}
int EMPTYS(SqStack S)
{
    if(S.top==-1)return 1;
    else return 0;
}
int FULLS(SqStack S)
{
    if(S.top==MaxSize-1)return 1;
    else return 0;
}
int PUSH(SqStack *S,int e)
{
    if(S->top==MaxSize-1){
        printf("error ");
        return 0;
    }
    else{
        S->top++;
        S->data[S->top]=e;
        return 1;
    }
}
int POP(SqStack *S,int *e)
{
    if(S->top==-1){
        printf("error ");
        return 0;
    }
    else{
        *e=S->data[S->top];
        printf("%d ",*e);
        S->top--;
        return 1;
    }
}
int main()
{
    SqStack S;
    INITIALS(&S);
    int e;
    int choice;
    while((scanf("%d",&choice))!=EOF){
        switch(choice){
            case 1:{
                scanf("%d",&e);
                PUSH(&S,e);
                break;
            }
            case 0:{
                POP(&S,&e);
                break;
            }
            case -1:
                return 0;
        }
    }
    return 0;
}

