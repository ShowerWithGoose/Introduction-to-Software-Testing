#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
typedef struct TreeNode *PtrToNode;
typedef struct TreeNode Tree;

struct TreeNode
{
	int data;
	int height;
	PtrToNode  left;
	PtrToNode  right;
};
/*PtrToNode MakeEmpty( PtrToNode T )//½¨Á¢¿ÕÊ÷ 
{
	if( T != NULL )
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);  
	}
	return NULL;
}
PtrToNode Find(int x, PtrToNode T)
{
	if(T==NULL) return NULL;
	if(x<T->data) return Find(x,T->left);
	else if(x>T->data) return Find(x, T->right);
	else return T;
} */
void Insert (int x, PtrToNode *T,int height)
 {
 	if(*T==NULL)
 	{
	 	*T = (PtrToNode) malloc(sizeof(Tree));
			(*T)->data=x;
			(*T)->height=height;
			(*T)->left=(*T)->right=NULL;
	}
	else 
	if(x<(*T)->data)
		Insert(x,&((*T)->left),height+1);
	else 
		Insert(x,&((*T)->right),height+1);

 }
 void printleaf(PtrToNode T)
 {
	if(T!=NULL)
	{
		printleaf(T->left);
		if(T->left==NULL&&T->right==NULL) printf("%d %d\n",T->data,T->height);
		printleaf(T->right);
	}
 }
int n,temp;
PtrToNode BSTree=NULL;
int main(){
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		Insert(temp,&BSTree,1);	
	}
	printleaf(BSTree);
return 0;
}

