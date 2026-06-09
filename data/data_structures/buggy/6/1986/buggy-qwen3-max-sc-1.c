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
        printf(" error "); // @@ There's an extra space before "error", which causes output mismatch.
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
            scanf("%d",&n); // @@ This scanf reads the next operation inside the loop, but if the input ends with -1 immediately after a valid operation, it may not be read correctly. Also, this structure duplicates scanf logic and may skip or misread inputs.
        }else if(n==0){
            pop();
            scanf("%d",&n); // @@ Same issue as above: duplicated scanf leads to potential input misalignment.
        }
    }
    
    
    return 0;
}