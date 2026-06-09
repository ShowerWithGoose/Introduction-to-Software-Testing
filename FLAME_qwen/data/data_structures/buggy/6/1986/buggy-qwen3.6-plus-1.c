#include<stdio.h>
#include<stdlib.h>
#define max 100
struct Node{
    int x;
    struct Node *link;
};
typedef struct Node node;
typedef struct Node *nodeptr;
nodeptr top; int cnt=0; // @@ Add counter to track stack size for capacity check
void initstack(){
    top=NULL;
}
int isEmpty(){
    return top==NULL;
}
void push(int a){
    nodeptr p;
    if(cnt>=max || (p=(nodeptr)malloc(sizeof(node)))==NULL){ // @@ Check stack full condition and malloc failure
        printf("error ");
    }else{
        p->x=a;
        p->link=top;
        top=p; cnt++; // @@ Increment counter on successful push
    }    
}
void pop(){
    nodeptr p;
    int a;
    if(isEmpty()){
        printf("error "); // @@ Remove leading space in error message to match expected output
    }else{
        p=top;
        a=top->x;
        top=top->link;
        free(p);
        printf("%d ",a); cnt--; // @@ Decrement counter on successful pop
    }
}
int main(){
    int n,m;
    
    scanf("%d",&n);
    while(n!=-1){
        if(n==1){
            scanf("%d",&m);
            push(m);
            scanf("%d",&n);
        }else if(n==0){
            pop();
            scanf("%d",&n);
        }
    }
    
    
    return 0;
}