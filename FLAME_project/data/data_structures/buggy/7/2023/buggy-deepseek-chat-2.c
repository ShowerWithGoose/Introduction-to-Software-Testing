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
                        p->h=h+1; // @@ [Error: The root node's height should be 1, but here the root's height is never set. When the first node is inserted as root, p->h is uninitialized. For subsequent nodes, the height calculation is off by one because h starts at 1 for the root, but the root's height should be 1, so the child's height should be h+1 = 2, which is correct. However, the root node's h is never set, leading to undefined behavior when printing.]
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
                        p->h=h+1; // @@ [Same error as above: root's h is not initialized, and for other nodes, the height calculation is correct but the root's missing initialization causes wrong output for single-node case.]
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