#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
	int data;
	struct node *left,*right;
}Node;
typedef struct node2{
	int data;
	int seque;
}Node2;
Node2 res[1000];
int top=-1;
Node *root,*point,*queue[1000];
int front,rear,cnt=1,test[100],t_top=-1;
void see(Node *rot){
	if(!rot){
		return; 
	}
	cnt++;
	see(rot->left);
	cnt--;
	cnt++;
	see(rot->right);
	cnt--;
	if(!rot->left&&!rot->right){
		res[++top].data=rot->data;
		res[top].seque=cnt;
	}
	return ;
}
int main(){
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		Node *point=(Node *)malloc(sizeof(Node));
		point->data=temp;
		point->left=point->right=NULL;
		if(!root){
			root=point;
		}
		else{
			Node *serch,*pre;
			serch=pre=root;
			while(serch){
				pre=serch;
				if(serch->data>temp){
					serch=serch->left;
				}
				else{
					serch=serch->right;
				}
			}
			if(temp>=pre->data){
				pre->right=point; 
			}
			else{
				pre->left=point;
			}
		}
	} 
	see(root);
	for(int i=0;i<=top;i++){
		printf("%d %d\n",res[i].data,res[i].seque);
	}
	return 0;
} 
//13
//50 38 30 64 58 40 10 73 70 50 60 100 35

