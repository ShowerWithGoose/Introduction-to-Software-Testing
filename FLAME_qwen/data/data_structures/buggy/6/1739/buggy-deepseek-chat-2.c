#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack;
int main(){
    stack S;
    S->top=-1; // @@ [S is an uninitialized pointer; dereferencing it causes undefined behavior. It should be allocated memory with malloc or declared as a struct variable instead of a pointer.]
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
            if(S->top==MAXSIZE-1){ // @@ [S is uninitialized; accessing S->top is invalid.]
                printf("error ");
            }
            else{
                S->top++; // @@ [S is uninitialized; modifying S->top is invalid.]
                S->date[S->top]=e; // @@ [S is uninitialized; accessing S->date is invalid.]
            }
        }
        else if(n==0){
            if(S->top==-1){ // @@ [S is uninitialized; accessing S->top is invalid.]
                printf("error ");
            }
            else{
                printf("%d ",S->date[S->top]); // @@ [S is uninitialized; accessing S->date is invalid.]
                S->top--; // @@ [S is uninitialized; modifying S->top is invalid.]
            }
        }
    }
}