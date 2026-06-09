#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct tree{
	int num;
	struct tree *rleaf,*lleaf;
}; 
typedef struct tree Tree;
typedef struct Leaf *leaf;
Tree *planttree(int data,Tree *S);
void printleaf(Tree *root,int high);

int main() 
{
	Tree *root=NULL;//建立一颗二叉树
	int i,n;
	int data;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=planttree(data,root);
	}
    printleaf(root,1);
    return 0;
}



Tree *planttree(int data,Tree *root)
{
	if(root==NULL){
		root=(Tree *)malloc(sizeof(Tree));
		root->num=data;
		root->lleaf=root->rleaf=NULL;
		return root;}
	else if(data<root->num){
		root->lleaf=planttree(data,root->lleaf);
		return root;}
	else if(data<root->num){
		root->lleaf=planttree(data,root->lleaf);
		return root;}
	else if(data>=root->num){
		root->rleaf=planttree(data,root->rleaf);
		return root;}
	else
	return root;
}
void printleaf(Tree *root,int high){
	if(root!=NULL){
	if (root->lleaf == NULL && root->rleaf == NULL) {
	    printf("%d %d\n",root->num,high);
		return;
	}//当是叶子时就打印 
	printleaf(root->lleaf,high+1);
	printleaf(root->rleaf,high+1);
	} 
}




