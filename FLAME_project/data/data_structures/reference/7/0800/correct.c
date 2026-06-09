#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
typedef int Datatype;
int flag=0;
struct node {
    Datatype data;
    Datatype height;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
 void  postorder(BTNodeptr t)
{
      if(t!=NULL){
             postorder(t->left);
             postorder(t->right);
             visit(t);       /* 访问T指结点  */
      }
}

void visit(BTNodeptr t) {
if(t!=NULL&&t->left==NULL&&t->right==NULL) 
	printf("%d %d\n",t->data,t->height );

}
 

int main()
{
    int i, item;
    BTNodeptr  root=NULL;
    int num;
    scanf("%d",&num);
    for(i=1; i<=num; i++){ //构造一个有10个元素的BST树
         scanf(" %d", &item);
         root = insertBST(root, item);
     }
    postorder(root);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->height=++flag;
        flag=0;
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if( item < p->data){
    	flag++;
        p->left = insertBST(p->left, item);
		}
    else if( item >= p->data){
    	flag++;
    	p->right = insertBST(p->right, item);
	}
    return p;
} 
 


