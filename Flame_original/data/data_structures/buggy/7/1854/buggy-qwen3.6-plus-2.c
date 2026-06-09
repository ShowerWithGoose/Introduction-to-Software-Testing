#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
struct Bnode{
    int data;
    struct Bnode* lchild;
    struct Bnode* rchild;
};
typedef struct Bnode BNODE;
typedef struct Bnode* BNodeptr;
int a[100];
BNodeptr head=NULL;
void visit(BNodeptr t){
    //左右孩子都没有=度为0=叶结点 
    if(t->lchild==NULL&&t->rchild==NULL){
        int answer=0;
        answer=howhigh(head,t->data,1); // @@ Passing the value t->data instead of the node pointer t causes incorrect height calculation when duplicate values exist in the BST, as the search may stop at an ancestor with the same value.
        printf("%d %d\n",t->data,answer);
    }
}
void postorder(BNodeptr t){
    if(t!=NULL){
        postorder(t->lchild);
        postorder(t->rchild);
        visit(t);
    }
}
int howhigh(BNodeptr p,int key,int level){
    if(p==NULL){
        return 0;//树空了 
    }
    if(p->data==key&&p!=head){ // @@ Comparing by value fails for duplicate values allowed by the problem, and the p!=head condition incorrectly prevents returning the correct height (1) when the root itself is a leaf node. It should compare node pointers instead.
        return level;
    }
    if(p->data>key){
        return howhigh(p->lchild,key,level+1);
    }
    return howhigh(p->rchild,key,level+1);
}
int main(){
    BNodeptr p=NULL,q=NULL;
    int n;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int j; // @@ In strict C89 environments, declaring variables after executable statements (like the for loop above) causes a compilation error. Additionally, 'j' is unused.
    for(i=1;i<=n;i++){
        p=(BNodeptr)malloc(sizeof(BNODE));
        p->data=a[i];
        p->lchild=NULL;
        p->rchild=NULL;        
        if(head==NULL){
            head=p;
        }
        else{
            q=head;
            while(1){
                if(a[i]<q->data){
                    if(q->lchild!=NULL){
                        q=q->lchild;
                    }
                    else{
                        q->lchild=p;
                        break;
                    }
                }
                else{
                    if(q->rchild!=NULL){
                        q=q->rchild;
                    }
                    else{
                        q->rchild=p;
                        break;
                    }
                }
            }
        }
    }
    postorder(head);
    return 0;
}