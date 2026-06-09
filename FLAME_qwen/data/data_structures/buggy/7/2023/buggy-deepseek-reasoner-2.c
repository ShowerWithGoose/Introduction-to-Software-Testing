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
            root=p; // @@ [Root node's height (p->h) is not set. Should be p->h=1;]
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
                        p->h=h+1;
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
                        p->h=h+1;
                        break;
                    }
                }
            }
        }
    }
} // @@ [Function 'creat' is supposed to return a TREEPTR but has no return statement. This causes undefined behavior and may lead to compilation error if warnings are treated as errors.]
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