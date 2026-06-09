#include <stdio.h>
#include <stdlib.h>
#define MAXH 200
typedef struct tree{
    int x;
    int h;
    struct tree *llink;
    struct tree *rlink;
}TREE,*TREEPTR;
TREEPTR root=NULL;
TREEPTR creat(int n);
TREEPTR STACK[MAXH];
int top=-1;
void Print(TREEPTR root);
int main() {
    int n;
    scanf("%d",&n);
    creat(n);
    Print(root);
    return 0;
}
TREEPTR creat(int n){
    for(int i=0;i<n;i++){
        TREEPTR p=(TREE*)malloc(sizeof(TREE));
        p->llink=NULL;
        p->rlink=NULL;
        scanf("%d",&p->x);
        if(root==NULL){
            root=p;
            continue;
        }
        else{
            TREEPTR q=root;
            int h=1;
            while(1){
                if(q->x>p->x){
                    if(q->llink!=NULL){
                        q=q->llink;
                        h++;
                    }
                    else {
                        q->llink=p;
                        p->h=h+1; // @@ [Error: The height of the root node should be 1, but here when inserting the first child, h starts at 1 and p->h is set to h+1=2, making the child's height 2 instead of 2 (which is correct for a child), but the root node's height is never set. When n=1, the root node is created but its h field is not initialized, leading to undefined behavior. The expected output for a single node is height 1, but the root's h is uninitialized, so the output is 0.]
                        break;
                    }
                }
                else {
                    if(q->rlink!=NULL){
                        q=q->rlink;
                        h++;
                    }
                    else {
                        q->rlink=p;
                        p->h=h+1; // @@ [Same error as above: root's h is not set, and for n=1, the root's h is uninitialized.]
                        break;
                    }
                }
            }
        }
    }
}
void Print(TREEPTR root){
    TREEPTR p=root;
    if(root!=NULL){
        do{
            while(p!=NULL){
                STACK[++top]=p;
                p=p->llink;
            }
            p=STACK[top--];
            if(p->llink==NULL&&p->rlink==NULL){
                printf("%d %d\n",p->x,p->h);
            }
            p=p->rlink;
        }while(!(p==NULL&&top==-1));
    }
}