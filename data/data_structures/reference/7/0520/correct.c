#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct TreeNode* treeptr;
int n,num,degree=1; 
struct TreeNode{
	int data;
	struct TreeNode *lptr;
	struct TreeNode *rptr;
	int degree;
};
struct TreeNode tree;
struct TreeNode *t=NULL;
void create(treeptr *p,int num,int degree);
void mid(struct TreeNode *p); 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		create(&t,num,1);//传入t的地址 就是p的值 
	}
	//输出叶节点和度 
	// 中序遍历
	 mid(t);
	
	
	
	return 0;
 } 
 void create(struct TreeNode **p,int num,int degree)//p是指向t的指针 t指向结构体 
 {
 	if(*p==NULL)
 	{
 		*p=(struct TreeNode *)malloc(sizeof(struct TreeNode));
 		(*p)->lptr=NULL;
 		(*p)->rptr=NULL;
 		(*p)->degree=degree;
 		(*p)->data=num;
	 }
	 else if((*p)->data>num)
	 {
	 	degree++;
	 	create(&(*p)->lptr,num,degree);
	 }
	 else
	 {
	 	degree++;
	 	create(&(*p)->rptr,num,degree);
	 }
 }
 void mid(treeptr p)
 {
 	if(p!=NULL)
	 {
	 	mid(p->lptr);
	 	if(p->lptr==NULL&&p->rptr==NULL)
	 	{
	 		printf("%d %d\n",p->data ,p->degree);
		 }
		 mid(p->rptr);
	  } 
 }

