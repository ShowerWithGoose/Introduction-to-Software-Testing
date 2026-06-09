#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
//int·¶Î§£º2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
struct tree{
	int data,height;
	struct tree *left,*right;
}*root=NULL,*q,*p,*inroot=NULL;
typedef struct tree* list;
int mark=0;
list create(int num,int h);
list add(int num,list root);
void preorder(list inroot);

int main(){
	int n,a[107];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		root=add(a[i],root);
	}
	inroot=root;
	preorder(inroot);
	return 0;	
}

list create(int num,int h){
	q=(list)malloc(sizeof(list));
	q->left=NULL,q->right=NULL;
	q->data=num;
	q->height=h;
	return q;
};

list add(int num,list root){
	int h=1;
	if(root==NULL){
		q=create(num,h);
		root=q;
		return root;
	}
	else{
		mark=0;
		q=root;
		while(mark!=1){
			if(num<q->data){
				if(q->left!=NULL) q=q->left,h++;
				else{
					p=q,h++;
					q=create(num,h);
					p->left=q;
					mark=1;
				}
			} 
			else if(num>=q->data){
				if(q->right!=NULL) q=q->right,h++;
				else{
					p=q,h++;
					q=create(num,h);
					p->right=q;
					mark=1;
				}
			} 
		}
		return root;
	}
};

void preorder(list inroot){
	if(inroot!=NULL){
		if(inroot->left==NULL&&inroot->right==NULL) printf("%d %d\n",inroot->data,inroot->height);
		preorder(inroot->left);
		preorder(inroot->right);
	}
};



