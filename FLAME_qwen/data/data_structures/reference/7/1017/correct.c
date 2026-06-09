#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};

typedef struct node BTNode; 
typedef struct node* BTNodeptr;
void  postorder(BTNodeptr t);
BTNodeptr  insertBST(BTNodeptr p, int item);
int HighBT(BTNodeptr );
BTNodeptr head;
int main(){
	int n,item;
	BTNodeptr  root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&item);
		root=insertBST(root, item);
	    if(i==0)
	    head=root;
	}
	postorder(head);
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
    else if( item >=p->data)
       p->right = insertBST(p->right,item);
    else   
    {}
    return p;
}
void  postorder(BTNodeptr t)
{
      if(t!=NULL){
      	if(t->left==NULL&&t->right==NULL){
		  	printf("%d %d\n",t->data,HighBT(t));
		  }
             postorder(t->left);
             postorder(t->right);
                
      }
}


int HighBT(BTNodeptr t)
{
	int high=1;
	 BTNodeptr p0=head;
  while(t!=p0){
  	high++;
  if(t->data<p0->data){
 	p0=p0->left;
  }
 	else
 	p0=p0->right;
 }       
 return high;     
}






