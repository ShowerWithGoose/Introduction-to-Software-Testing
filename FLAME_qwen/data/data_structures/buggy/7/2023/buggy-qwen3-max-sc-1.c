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
TREEPTR creat(int n); // @@ [Function 'creat' is declared to return TREEPTR but does not return anything when n > 0, leading to undefined behavior. Also, it should return void since it modifies the global 'root'.]
TREEPTR STACK[MAXH];
int top=-1;
void Print(TREEPTR root);
int main() {
    int n;
    scanf("%d",&n);
    creat(n); // @@ [The function 'creat' is used for its side effect (modifying global 'root'), but its return value is ignored. However, the real issue is that 'creat' doesn't initialize 'h' for the root node.]
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
            continue; // @@ [When inserting the root node, its height 'h' is never initialized. According to problem, root height should be 1.]
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
} // @@ [Missing return statement for non-void function. Should either return a value or be declared as void.]
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
                printf("%d %d\n",p->x,p->h); // @@ [If root was inserted without initializing 'h', accessing 'p->h' here leads to undefined behavior (garbage value).]
            }
            p=p->rlink;
        }while(!(p==NULL&&top==-1));
    }
}