#include<stdio.h>
#include<string.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, int item);
void  perorder(BTNodeptr t);
int sto=0;
int main()
{
     int i=0, n=0,item=0;
    BTNodeptr  root=NULL;
    scanf("%d",&n);
      for(i=0; i<n; i++){ //构造一个有10个元素的BST树
         scanf("%d", &item);
         root = insertBST(root, item);
     }
    perorder(root);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, int item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;        
    } 
    else if( item < p->data)
    p->left = insertBST(p->left, item);
    else if( item >= p->data)
       p->right = insertBST(p->right,item);
    return p;
} 
void  perorder(BTNodeptr t)
{
     sto++;
      if(t!=NULL){
            if(t->left==NULL&&t->right==NULL)       /* 访问t指向结点  */
            {
                printf("%d %d\n",t->data,sto);
            }
         
             perorder(t->left);
             perorder(t->right);
              
       } 
        sto--;
}

