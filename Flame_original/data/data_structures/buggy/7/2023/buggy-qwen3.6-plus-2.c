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
    for(int i=0;i<n;i++){ // @@ Declaring loop variable 'i' inside the for loop initializer is a C99 feature and will cause a compilation error in C89/C90 standard environments.
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
} // @@ Function 'creat' is declared to return TREEPTR but lacks a return statement, causing a compilation error in strict compiler modes.
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