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
        answer=howhigh(head,t->data,1); // @@ [The function howhigh assumes that all node values are unique, but BST allows duplicates (right child >= root). When duplicates exist, howhigh may find the wrong node (e.g., an ancestor or sibling with same value) and return incorrect height. Also, condition `p!=head` in howhigh is incorrect—it excludes root even if root is a leaf.]
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
    if(p->data==key&&p!=head){ // @@ [Incorrectly excludes the root node (`head`) from being recognized as the target node. If the root is a leaf, this condition fails to match it, leading to wrong traversal and possibly returning 0 or wrong height. Should not have `&& p!=head`.]
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
    int j;
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