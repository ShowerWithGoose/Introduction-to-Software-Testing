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
BTNodeptr  insertBST(BTNodeptr p, Datatype num);
 void  postorder(BTNodeptr root)
{
      if(root!=NULL){
             postorder(root->left);
             postorder(root->right);
             visit(root);       /* 访问T指结点  */
      }
}

void visit(BTNodeptr root) {
if(root!=NULL&&root->left==NULL&&root->right==NULL) 
	printf("%d %d\n",root->data,root->height );

}
 

int main()
{
    int i, num;
    BTNodeptr  root=NULL;
    int n;
    scanf("%d",&n);
    for(i=1; i<=n; i++){ //构造一个有10个元素的BST树
         scanf(" %d", &num);
         root = insertBST(root, num);
     }
    postorder(root);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype num)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->height=++flag;
        flag=0;
        p->data = num;
        p->left = p->right = NULL;
    } 
    else if( num < p->data){
    	flag++;
        p->left = insertBST(p->left, num);
		}
    else if( num >= p->data){
    	flag++;
    	p->right = insertBST(p->right, num);
	}
    return p;
} 
 


