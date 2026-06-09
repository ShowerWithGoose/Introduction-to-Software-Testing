#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef int Datatype;
 struct node {
          Datatype data;
          Datatype depth;
          struct  node  *left, *right;
   };
typedef struct node BTNode;
typedef struct node *BTNodeptr;
int depth=1;
void visit(BTNodeptr T){
	printf("%d %d\n",T->data,T->depth);
}
void perorder(BTNodeptr T){
	      if(T!=NULL){
            
             perorder(T->left);
             if(T->left==NULL && T->right==NULL){
             	visit(T);
			 }
             perorder(T->right);
       }

}

BTNodeptr insertBST(BTNodeptr T, Datatype item,Datatype depth){
	if(T == NULL){
        T = (BTNodeptr)malloc(sizeof(BTNode));
        T->data = item;
        T->left = T->right = NULL;
        T->depth=depth;
    }
    else if(item < T->data){
    	 T->left = insertBST(T->left,item,depth+1);
	}
	else if( item >= T->data){
       T->right = insertBST(T->right,item,depth+1);
   }
   return T;
}

int main()
{
int n;
scanf("%d",&n);
BTNodeptr root=NULL;
int i;
int item;
for(i=0;i<n;i++){
	scanf("%d",&item);
	root = insertBST(root,item,depth);
}
perorder(root);
return 0;
}





