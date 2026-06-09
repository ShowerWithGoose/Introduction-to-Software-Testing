#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Datatype;
struct node{
	Datatype data;
	struct node *left,*right;
};
typedef struct node TBTNode;
typedef struct node *TBTNodeptr;
TBTNodeptr  insertBST(TBTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (TBTNodeptr)malloc(sizeof(TBTNode));
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data||item == p->data)
       p->right = insertBST(p->right,item); 
    return p;
} 
void  insertTBST(TBTNodeptr p, Datatype k)
{
    if(p->left!=NULL){
    	k+=1;
    	insertTBST(p->left, k);
    	k-=1;
	}
    if(p->right!=NULL){
    	k+=1;
	    insertTBST(p->right,k);
	    k-=1;
    }  
    if(p->left==NULL&&p->right==NULL) {
    	printf("%d %d\n",p->data,k);
    	return ;
	}
    return ;
} 
int main(){
	int i,m,n,k=1;
	TBTNodeptr root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		root = insertBST(root,m);
     }
    insertTBST(root,k);
    return 0;
} 

