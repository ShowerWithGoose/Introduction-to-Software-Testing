#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    int height;
    struct node *left,*right,*father;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,BTNodeptr fa, int item)
{
	if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->father=fa;
        p->data = item;
        p->left = p->right = NULL;
        p->height=fa->height+1;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left,p,item);
    else 
       p->right = insertBST(p->right,p,item);
    return p;
}
void  preorder(BTNodeptr t)
{
      if(t!=NULL){
            
			if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->data,t->height);
             preorder(t->left);
             preorder(t->right);
       }
       else return ;
}

int main()
{
    int n,item;
    scanf("%d",&n); 
	BTNodeptr root=NULL;
    BTNodeptr head=root;
   	scanf("%d", &item);
   	root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head;
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
	{
        scanf("%d", &item);
        root = insertBST(root,head,item);
    }
    preorder(root);
    return 0;
}

