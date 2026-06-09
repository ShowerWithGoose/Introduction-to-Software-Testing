#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
    int date[MAXSIZE];
    int top;
}*stack;
int main(){
    stack S; // @@ [Error: 'S' is an uninitialized pointer. It points to random memory. Dereferencing it causes a segmentation fault. It should be a struct instance or allocated memory.]
    S->top=-1; // @@ [Error: Dereferencing uninitialized pointer 'S' leads to undefined behavior/crash.]
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
            if(S->top==MAXSIZE-1){ // @@ [Error: Accessing member of uninitialized/invalid pointer 'S'.]
                printf("error ");
            }
            else{
                S->top++; // @@ [Error: Accessing member of uninitialized/invalid pointer 'S'.]
                S->date[S->top]=e; // @@ [Error: Accessing member of uninitialized/invalid pointer 'S'.]
            }
        }
        else if(n==0){
            if(S->top==-1){ // @@ [Error: Accessing member of uninitialized/invalid pointer 'S'.]
                printf("error ");
            }
            else{
                printf("%d ",S->date[S->top]); // @@ [Error: Accessing member of uninitialized/invalid pointer 'S'.]
                S->top--; // @@ [Error: Accessing member of uninitialized/invalid pointer 'S'.]
            }
        }
    }
}