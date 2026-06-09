#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree {
    int data;   
    struct tree *left;
    struct tree *right;
};
typedef struct tree Tree;
void putin(Tree **t,int num)
{
	Tree *temp=NULL;
    if(!(*t)){
        temp=(Tree *)malloc(sizeof(Tree));
        temp->left=temp->right=NULL;
        temp->data=num;
        *t=temp;
        return;
        
    }
    if(num<(*t)->data){
        putin(&(*t)->left,num);
    }else if (num>=(*t)->data){
        putin(&(*t)->right,num);
    }
}
void printtree(Tree *t,int h)
{
	
	if(t){
	    if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->data,h);
		else{
		h++;
		printtree(t->left,h);
        printtree(t->right,h);
    }  
	}
}
int main()
{
	int n,num;
	Tree *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		putin(&root,num);
	}
	printtree(root,1);
}

