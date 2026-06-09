#include <stdio.h>
#include <stdlib.h>
struct tree{
    int num;
    struct tree *lchild;
    struct tree *rchild;
    int level;
};
typedef struct tree *Tree;
void pout(Tree t){
    if(t->lchild!=NULL||t->rchild!=NULL){ // @@ This condition does not guard against NULL children; when a node has only one child, the recursive calls on line 12 or 13 pass NULL, causing a segmentation fault inside the next pout call.
        pout(t->lchild);
        pout(t->rchild);
    }else{
        printf("%d %d\n",t->num,t->level);
    }
}
int main()
{
    Tree t=(Tree)malloc(sizeof(struct tree));
    t->level=1;
    t->lchild=NULL;
    t->rchild=NULL;
    int n=0;
    scanf("%d",&n);
    int tmp;
    scanf("%d",&t->num);
    for(int i=0;i<n-1;i++){
        scanf("%d",&tmp);
        Tree p=t;
        Tree q=t;
        int le=1;
        while(p!=NULL){
            if(tmp>=p->num){
                q=p;
                p=p->rchild;
                le++;
            }else{
                q=p;
                p=p->lchild;
                le++;
            }
        }
        if(tmp>=q->num){
            q->rchild=(Tree)malloc(sizeof(struct tree));
            q->rchild->num=tmp;
            q->rchild->lchild=NULL;
            q->rchild->rchild=NULL;
            q->rchild->level=le;
        }else{
            q->lchild=(Tree)malloc(sizeof(struct tree));
            q->lchild->num=tmp;
            q->lchild->lchild=NULL;
            q->lchild->rchild=NULL;
            q->lchild->level=le;
        }
    }
    pout(t);
    return 0;
}