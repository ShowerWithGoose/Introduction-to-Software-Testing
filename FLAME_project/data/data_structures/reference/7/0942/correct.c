#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    int data;
    // int high;
    struct Node *lchild,*rchild;
};
typedef struct Node node;
typedef struct Node* nodeptr;
int height=0;
nodeptr insert(nodeptr p,int item){
    if(p==NULL){
        p=(nodeptr)malloc(sizeof(node));
        p->data=item;
        // p->high=height;
        p->lchild=p->rchild=NULL;
    }else if(item<p->data){
        p->lchild=insert(p->lchild,item);
    }else 
        p->rchild=insert(p->rchild,item);
    return p;
}
void order(nodeptr t){
    if(t!=NULL){
        height++;
        order(t->lchild);
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,height);
        }
        order(t->rchild);
        height--;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int item;
    nodeptr root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&item);
        root=insert(root,item);
    }    
    // printf("%d",root->data);
    order(root);
    return 0;
}
