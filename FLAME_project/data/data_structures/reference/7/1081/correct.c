#include <stdio.h>//建立一个树然后去遍历到叶节点，然后从左到右输出叶节点的度
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
struct bst
{
   int data;
   struct bst* left;
   struct bst* right;
};
struct bst* shu(struct bst* root,int goal)
{
   if(root==NULL)
   {
       root=(struct bst*)malloc(sizeof(struct bst));
       root->data=goal;
       root->left=NULL;root->right=NULL;
   }
   else if(goal>=root->data)
   {
       root->right=shu(root->right,goal);
   }
   else if(goal<root->data)
   {
       root->left=shu(root->left,goal);
   }
   return root;
}
int du=0;
void frontseek(struct bst* root,int du)
{
	if(root!=0)
	{
		 du++; 
		  frontseek(root->left,du);
		     if(root->right==NULL&&root->left==NULL)
    {
       printf("%d %d\n",root->data,du);
       
    } 
        frontseek(root->right,du);
	 } 
}

int main()
{   
    int num,a;
    int du=0;
    int i,j,k;
    struct bst *root=NULL;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&a);
        root=shu(root,a);
    }//建立好了树前序遍历
    frontseek(root,du);
    return 0;
}

