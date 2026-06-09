#include <stdio.h>
#include <string.h>
typedef struct node{
    int item;
    struct node *left, *right;
}Node, *Nodeptr; 
Nodeptr insert(Nodeptr p, int n){
    if(p==NULL){
        p=(Nodeptr)malloc(sizeof(Node));
        p->item=n;
        p->left=p->right=NULL;
    }

    else if(n<p->item)
    p->left=insert(p->left,n);
    else if(n>=p->item)
    p->right=insert(p->right,n);

    return p;
} 

void DFStree(Nodeptr t, int depth){
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL)printf("%d %d\n",t->item,depth);
        DFStree(t->left,depth+1);        
        DFStree(t->right, depth+1);
        
    }
    
}
    

int main()
{
int all;
int item;
Nodeptr root=NULL;
scanf("%d",&all);
for(int i=0; i<all; i++){
    scanf("%d",&item);
    root=insert(root,item);
}
DFStree(root,0); // @@ The initial depth passed to DFStree is 0, but the problem states that the height of the root node is 1. It should be DFStree(root, 1).
return 0;
}