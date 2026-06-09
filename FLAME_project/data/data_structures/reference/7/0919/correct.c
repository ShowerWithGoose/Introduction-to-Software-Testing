#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	int height;
	struct node* lchild;
	struct node* rchild;
};
struct node* root,q;
struct node* insertItem(struct node* p,struct node* ptr)
 {
 	if(p == NULL)
 	{
 		p = ptr;
	 }
	 else if(p->num > ptr->num)
	 {
	 	ptr->height ++;
	 	p->lchild = insertItem(p->lchild,ptr);
	 }
	 else if(p->num <= ptr->num)
	 {
	 	ptr->height ++;
	 	p->rchild = insertItem(p->rchild,ptr);
	 }
	 return p;
 }
void printLeaf(struct node* root)
 {
 	if(root != NULL)
 	{
// 		visit(root);
    if(root->lchild == NULL && root->rchild == NULL)
	{
		printf("%d %d\n",root->num,root->height);
	}
 		printLeaf(root->lchild);
 		printLeaf(root->rchild);
	 }
 }
//void visit(struct node* p)
//{
	
//}
int main()
{
	int i,n,item;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
	    struct node* ptr = (struct node*)malloc(sizeof(struct node));
		ptr->num = item;
		ptr->height = 1;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		root = insertItem(root,ptr);
	}
	printLeaf(root);
	return 0;
}















 

