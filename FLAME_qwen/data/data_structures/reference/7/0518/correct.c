#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
typedef struct TreeNode *BinTree;
struct TreeNode{
		int data;
		BinTree left;
		BinTree right; 
};
void FindLeaves(BinTree BT,int cur){
	if(BT){
		if( !BT->left && !BT->right)
			printf("%d %d\n",BT->data,cur);  
		FindLeaves(BT->left,cur+1);   
		FindLeaves(BT->right,cur+1);  
	}
}
BinTree insert(int n,BinTree BT){
	if(!BT){
		BT = (BinTree)malloc(sizeof(struct TreeNode));
		BT->data = n;
		BT->left = NULL;
		BT->right = NULL;
	}
	else{
		if(n<BT->data)
		BT->left=insert(n,BT->left);
		else
		BT->right=insert(n,BT->right);
	}
	return BT;
}
int main(){
	BinTree BT = NULL;
	int i,n,data;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		BT=insert(data,BT);
	}
	FindLeaves(BT,1);
	return 0;
}


