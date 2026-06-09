#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TNode{
	int name;
	int height;
	struct TNode* left;
	struct TNode* right;
};
struct TNode* Root = NULL;
void Print(struct TNode* now);
void Insert(struct TNode* now,int value);
int main()
{
	int i,n,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&temp);
		Insert(Root,temp);
	}
	Print(Root);
    return 0;
}
void Print(struct TNode* now)
{
	if(now->left==NULL&&now->right==NULL) printf("%d %d\n",now->name,now->height);
	if(now->left!=NULL) 	Print(now->left);
	if(now->right!=NULL) Print(now->right);
}

void Insert(struct TNode* now,int value)
{
	if(Root==NULL){
		Root = (struct TNode*)malloc(sizeof(struct TNode));
		Root->name = value;
		Root->height = 1;
		Root->left = Root->right = NULL;
		return;
	}
	if(now->name > value){
		if(now->left==NULL){
			now->left = (struct TNode*)malloc(sizeof(struct TNode));
			now->left->name = value;
			now->left->height = 1;
			now->left->height = now->height+1;
			now->left->left = now->left->right = NULL;
			return;			
		}
		else{
			Insert(now->left,value);
			return;
		}
	}
	else{
		if(now->right==NULL){
			now->right = (struct TNode*)malloc(sizeof(struct TNode));
			now->right->name = value;
			now->right->height = 1;
			now->right->height = now->height+1;
			now->right->left = now->right->right = NULL;
			return;			
		}
		else{
			Insert(now->right,value);
			return;
		}		
	}
}

