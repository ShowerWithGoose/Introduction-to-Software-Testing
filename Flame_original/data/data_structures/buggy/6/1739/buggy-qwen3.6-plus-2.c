#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack;
int main(){
    stack S; // @@ S is declared as a pointer but no memory is allocated for it, leading to undefined behavior when dereferenced.
    S->top=-1; // @@ Dereferencing the uninitialized pointer S causes a segmentation fault. Memory should be allocated using malloc or S should be declared as a struct variable.
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