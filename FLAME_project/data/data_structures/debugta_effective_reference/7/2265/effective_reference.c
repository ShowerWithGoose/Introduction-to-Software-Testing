#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef int Datatype;
struct node {
    Datatype data;
    Datatype height;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item ,Datatype height);
void f(BTNodeptr p);
int main()
{
    int i,n,height=1,item;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++){ 
         scanf("%d", &item);
         root = insertBST(root, item,height);
     }
    f(root);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item,Datatype height)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->height=height;
        p->left = p->right = NULL;
    } 
    else if( item < p->data){
    	height++;
    	p->left = insertBST(p->left,item,height);	
	}
    else if( item >=p->data){
    	height++;
    	p->right = insertBST(p->right,item,height);
	}
    return p;
} 
void f(BTNodeptr p){
	if(p!=NULL){
		if(p->left==NULL&&p->right==NULL)
		printf("%d %d\n",p->data,p->height);
		f( p->left);
		f( p->right);
	}
}



