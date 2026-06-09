#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack;
int main(){
    stack S; // @@ [S is an uninitialized pointer; it does not point to allocated memory, leading to undefined behavior when dereferenced]
    S->top=-1;
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