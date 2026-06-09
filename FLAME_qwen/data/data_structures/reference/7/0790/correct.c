#include <stdio.h>
#include <stdlib.h>
struct node {
    int number;
    int deep;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr Root=NULL;
void  insertBST(int item);
void  inorder(BTNodeptr t);

int main()
{
	int N,item,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&item);
		insertBST(item);
	}
	inorder(Root);
}
void  insertBST(int item)
{
    BTNodeptr p, q;
    int k;
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->number=item;
    p->left=NULL;
    p->right=NULL;
    if(Root==NULL){
    	Root=p;
    	p->deep =1;}
	else{
		q=Root;
    	while(1) {
         	if(item<q->number)  {
         		k++;
             	if(q->left==NULL){
                    q->left=p;
                    p->deep =k+1;
                    break;
             	}	
             	else
                    q=q->left;
         	}	
         	else if (item>=q->number) {
         		k++;
              	if(q->right==NULL){
                    q->right=p;
                    p->deep =k+1;
                    break;     
             	}
             	else
                    q=q->right;
         	}
    	}
    }
}
void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->left);
             if(t->left ==NULL && t->right ==NULL)
             	printf("%d %d\n",t->number ,t->deep );
             inorder(t->right);
       }
}

