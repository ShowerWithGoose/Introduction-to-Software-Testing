#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack;
int main(){
    stack S;
    S->top=-1; // @@ [S is an uninitialized pointer; dereferencing it causes undefined behavior, likely a segmentation fault. The stack structure must be allocated memory (e.g., using malloc) before accessing its members.]
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
            if(S->top==MAXSIZE-1){ // @@ [Same issue: S is uninitialized, leading to undefined behavior.]
                printf("error ");
            }
            else{
                S->top++;
                S->date[S->top]=e; // @@ [Same issue: S is uninitialized.]
            }
        }
        else if(n==0){
            if(S->top==-1){ // @@ [Same issue: S is uninitialized.]
                printf("error ");
            }
            else{
                printf("%d ",S->date[S->top]); // @@ [Same issue: S is uninitialized.]
                S->top--;
            }
        }
    }
}