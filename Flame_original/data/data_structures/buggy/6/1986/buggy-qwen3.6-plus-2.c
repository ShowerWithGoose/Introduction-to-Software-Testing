#include<stdio.h>
#include<stdlib.h>
#define max 100
struct Node{
    int x;
    struct Node *link;
};
typedef struct Node node;
typedef struct Node *nodeptr;
nodeptr top;
void initstack(){
    top=NULL;
}
int isEmpty(){
    return top==NULL;
}
void push(int a){
    nodeptr p;
    if((p=(nodeptr)malloc(sizeof(node)))==NULL){ // @@ Checks for memory allocation failure instead of verifying the stack's maximum capacity of 100; should maintain a size counter and check if size >= max.
        printf("error ");
    }else{
        p->x=a;
        p->link=top;
        top=p;
    }    
}
void pop(){
    nodeptr p;
    int a;
    if(isEmpty()){
        printf(" error "); // @@ Incorrect output format; contains an extra leading space, should be "error ".
    }else{
        p=top;
        a=top->x;
        top=top->link;
        free(p);
        printf("%d ",a);
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