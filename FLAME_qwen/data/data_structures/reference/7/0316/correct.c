#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
}; 
struct node *insert(struct node *now,int num){
	if(now==NULL)
	{
		now=(struct node*)malloc(sizeof(struct node));
		now->data=num;
		now->left=NULL;
		now->right=NULL;
	}
	else if(num>=now->data)
	now->right=insert(now->right,num);
	else if(num<now->data)
	now->left=insert(now->left,num);
	return now;
}
int high=1;
int visit(struct node* now)
{
	if(now==NULL)
	return 1; 
	else 
	{
	if(now->left==NULL&&now->right==NULL)
	printf("%d %d\n",now->data,high);
	high++;
	visit(now->left);
	visit(now->right);
	high--;
	}
}
struct node* first=NULL;
int main(){
	int n;
	int i=0;
	int num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		first=insert(first,num);
	 } 
	visit(first);
	return 0;
} 


