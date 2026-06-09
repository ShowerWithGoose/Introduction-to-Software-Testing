#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 100
struct node
{
    int data;
    int x;
    struct node *left,*right;
};
typedef struct node BTNode, *BTNodeptr;
int n,i,j,k,a,b;
BTNodeptr  Root=NULL; //Root是一个全局变量
void  preorder(struct node *t)
{
      if(t!=NULL){
            //VISIT(t);       /* 访问t指向结点  */
            if(t->left==NULL&&t->right==NULL)
            {
            	printf("%d %d\n",t->data,t->x);
            	k=0;
			}
			else
			{
				//k++;
				preorder(t->left);
            	preorder(t->right);
			}
       }
}
void  midorder(struct node *t)
{
      if(t!=NULL){
            //VISIT(t);       /* 访问t指向结点  */
            //if(t->left==NULL&&t->right==NULL)             
            preorder(t->left);
			printf("%d ",t->data);
            preorder(t->right);
       }
}
BTNodeptr  insertBST(BTNodeptr p, int item,int b)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->x=b;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item,b+1);
    else if( item >= p->data)
       p->right = insertBST(p->right,item,b+1);
 //   else   
 //      do-something; //树中存在该元素
    return p;
}
int main()
{
    struct node* first,*p,*q;
    scanf("%d",&n);
    scanf("%d",&a);
    Root=(BTNodeptr)malloc(sizeof(BTNode));
    Root->data=a;
    Root->x=1;
    Root->left=Root->right=NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        Root=insertBST(Root,a,1);
    }
    preorder(Root);
    //printf("\n");
    //midorder(Root);
    //printf("UUU\n");
	return 0;
}

