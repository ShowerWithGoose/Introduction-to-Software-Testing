#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack;
int main(){
    stack S; // @@ S is a pointer to the struct but no memory is allocated; this leads to undefined behavior when accessed.
    S->top=-1; // @@ Dereferencing uninitialized pointer S; should allocate memory with malloc first.
    int n;
    int e;
    int c;
    while(scanf("%d",&n)!=EOF){
        e=0;
        c=0;
        if(n==-1){
            break;
        }
        else if(n==1){
            scanf("%d",&e);
            if(S->top==MAXSIZE-1){
                printf("error ");
            }
            else{
                S->top++;
                S->date[S->top]=e;
            }
        }
        else if(n==0){
            if(S->top==-1){
                printf("error ");
            }
            else{
                printf("%d ",S->date[S->top]);
                S->top--;
            }
        }
    }
}