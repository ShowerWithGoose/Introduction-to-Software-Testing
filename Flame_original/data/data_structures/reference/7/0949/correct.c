#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
struct node{
    Datatype val;
    int h;
    struct node *left,*right;
};
typedef struct node BTnode,*BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,Datatype item,BTNodeptr par);
void postorder(BTNodeptr root);
int main()
{
    int n,item;
    scanf("%d",&n);
    BTNodeptr root = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d",&item);
        root = insertBST(root,item,NULL);
    }
    postorder(root); 
    return 0;
}
BTNodeptr insertBST(BTNodeptr p,Datatype item,BTNodeptr par)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTnode));
        p->val = item;
        if(par != NULL)p->h= par->h + 1;
        else p->h = 1;
        p->left = NULL;
        p->right = NULL;
    }
    else if(item < p->val){
            p->left = insertBST(p->left,item,p);
        }
        else p->right = insertBST(p->right,item,p);
    return p;
}
void postorder(BTNodeptr t)
{
    if(t !=NULL){
        if(t->left != NULL)postorder(t->left);
        if(t->right != NULL)postorder(t->right);
    }
    if(t->left == NULL && t->right == NULL){
        printf("%d %d\n",t->val,t->h);
    }
}

