#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	int data;
	int h;
	BinTree left;
	BinTree right;
}; 
BinTree T=NULL;
BinTree Insertbst(BinTree T,int item,int cnt){
	cnt++;
	if(T==NULL){
		T=(BinTree)malloc(sizeof(BinTree));
		T->data =item;
		T->h=cnt;
		T->left=NULL;
		T->right=NULL;
	}
	else if(item< T->data )
		T->left=Insertbst(T->left,item,cnt);
	else
		T->right=Insertbst(T->right,item,cnt);
	return T;
}
void print(BinTree T)
{
    if (T)
    {
    	print(T->left);
        if (!(T->left) && !(T->right))
        {
            printf("%d %d\n", T->data, T->h);
        }
        
        print(T->right);
    }
}
//void Preorder(BinTree T)//ÖÐÐò±éÀú 
//{
//	if(T){
//		Preorder(T->left );
//		printf("%d %d\n",T->data ,T->h );
//		Preorder(T->right);
//	}
//}
int main()
{
	int n;
	scanf("%d",&n);
//	int flag=0;
//	BinTree BST=NULL;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
//		if(flag!=0){
		
			int x;
			scanf("%d",&x);
			T=Insertbst(T,x,cnt);	
//			flag=1;
//		}
//		else{
//			
//			int x;
//			scanf("%d",&x);
//			Insertbst(T,x,cnt);	
//		}
	}
//	Preorder(BST);
	print(T);
	return 0;
}


