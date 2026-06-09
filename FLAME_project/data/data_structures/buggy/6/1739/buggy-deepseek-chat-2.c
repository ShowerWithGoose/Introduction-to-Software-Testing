#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack; // @@ The pointer type `*stack` is defined but no actual stack structure is allocated in memory. `S` is a pointer that is never initialized with malloc, so accessing `S->top` causes undefined behavior (likely a segmentation fault).
int main(){
    stack S;
    S->top=-1; // @@ S is an uninitialized pointer; dereferencing it leads to undefined behavior. The program crashes here.
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