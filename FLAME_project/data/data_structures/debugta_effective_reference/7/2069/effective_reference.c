#include <stdio.h>
#include <stdlib.h>
struct node {
    int number;
    int deep;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr root=NULL;
void  insertBST(int x);
void  inorder(BTNodeptr k);

int main()
{
	int n,x,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insertBST(x);
	}
	inorder(root);
}
void  insertBST(int x)
{
    BTNodeptr p, q;
    int d;
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->number=x;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL){
    	root=p;
    	p->deep =1;}
	else{
		q=root;
    	while(1) {
         	if(x<q->number)  {
         		d++;
             	if(q->left==NULL){
                    q->left=p;
                    p->deep =d+1;
                    break;
             	}	
             	else
                    q=q->left;
         	}	
         	else if (x>=q->number) {
         		d++;
              	if(q->right==NULL){
                    q->right=p;
                    p->deep =d+1;
                    break;     
             	}
             	else
                    q=q->right;
         	}
    	}
    }
}
void  inorder(BTNodeptr k)
{
      if(k!=NULL){
             inorder(k->left);
             if(k->left ==NULL && k->right ==NULL)
             	printf("%d %d\n",k->number ,k->deep );
             inorder(k->right);
       }
}

