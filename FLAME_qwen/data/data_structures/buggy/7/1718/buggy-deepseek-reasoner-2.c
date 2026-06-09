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
    if(t->lchild!=NULL||t->rchild!=NULL){
        pout(t->lchild); // @@ calls pout on possibly NULL left child, causing segmentation fault
        pout(t->rchild); // @@ calls pout on possibly NULL right child, causing segmentation fault
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