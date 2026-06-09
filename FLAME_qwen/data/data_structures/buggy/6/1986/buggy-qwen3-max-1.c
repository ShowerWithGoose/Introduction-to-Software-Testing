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
        printf(" error "); // @@ [There is an extra space before "error", which causes output mismatch; should be "error " without leading space]
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
            scanf("%d",&n); // @@ [The input reading logic is flawed: it reads the next operation inside the if/else blocks, causing the last operation to be skipped or read incorrectly. The loop condition already reads 'n', so this extra scanf leads to skipping inputs or undefined behavior.]
        }else if(n==0){
            pop();
            scanf("%d",&n); // @@ [Same issue as above: redundant scanf inside loop body disrupts input sequence processing.]
        }
    }
    
    
    return 0;
}