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
            scanf("%d",&n); // @@ [The input reading logic is flawed: after processing an operation, it reads the next operation inside the if/else blocks, but if the last operation is -1, it may not be read correctly. Also, if an invalid operation (not 1, 0, or -1) is given, it's not handled. More critically, the loop condition checks n!=-1, but the first read is outside the loop, and subsequent reads happen only inside branches, which can lead to infinite loops or missed termination.]
        }else if(n==0){
            pop();
            scanf("%d",&n); // @@ [Same issue as above: inconsistent input reading pattern leads to potential logic errors in processing the sequence correctly.]
        }
    }
    
    
    return 0;
}