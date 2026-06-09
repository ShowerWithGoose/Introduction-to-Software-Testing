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
    if((p=(nodeptr)malloc(sizeof(node)))==NULL){
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
        printf(" error "); // @@ There's an extra space before "error", which causes output mismatch. Should be "error " like in push.
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
            scanf("%d",&n); // @@ This scanf reads the next operation inside the loop, but it skips processing if the last operation is -1 without reading it properly. Also, the loop condition checks n!=-1, but after processing an operation, it reads next n, which may miss the -1 termination if not handled correctly.
        }else if(n==0){
            pop();
            scanf("%d",&n); // @@ Same issue as above: this structure leads to double-reading and potential logic errors. The reference program uses a comma operator in while condition to read and check in one step.
        }
    }
    
    
    return 0;
}