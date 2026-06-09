#include "stdio.h"
#include "stdlib.h"
int m=1;
typedef struct node{ 
	int data; 
	struct node * left;
	struct node * right;
}Node;

typedef struct tree{ 
	Node *root;
}Tree;

void insert(Tree* tree, int value){    
 	Node *node=(Node*)malloc(sizeof(Node));    
 	node->data=value;    
 	node->left=NULL;    
 	node->right=NULL; 
	           
 	if (tree->root==NULL){        
 		tree->root=node;    
 	}    
 	else{        
 		Node *temp=tree->root;       
 		while (temp!=NULL){            
	 		if(value<temp->data){                
			 	if(temp->left==NULL){                    
				 	temp->left=node;                    
					return;                
				}                
				else{                    
					temp=temp->left;                
				}            
			}            
			else{                 
				if(temp->right==NULL){                    
					temp->right=node;                    
					return;                
				}                
				else{                    
					temp=temp->right;                
				}            
			}        
		}    
	}
}


void traverse(Node* node){
	int x=0;    
	if(node==NULL)    {   
		return;     
	}
	else{
		if(node->left == NULL&&node->right == NULL){
			printf("%d %d\n",node->data ,m);

		}
	}
	m++;
	traverse(node->left);
	traverse(node->right);
	m--;
}

int main(){
	int i,temp;
	int x=0;
	Tree tree;    
	tree.root=NULL;   
	int n;       
	scanf("%d",&n);    
	for(i=0;i<n;i++){                
		scanf("%d",&temp);        
		insert(&tree,temp);    
	}  
	traverse(tree.root);      
	return 0;
} 

