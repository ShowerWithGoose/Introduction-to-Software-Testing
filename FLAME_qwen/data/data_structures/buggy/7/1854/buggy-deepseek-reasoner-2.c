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
        answer=howhigh(head,t->data,1);
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
    if(p->data==key&&p!=head){ // @@ 错误：使用值比较且p!=head条件，当根节点是叶子时返回0；当树中有重复值时，会错误返回内部节点高度而非叶子节点高度。应改为通过节点指针比较并移除p!=head条件。
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