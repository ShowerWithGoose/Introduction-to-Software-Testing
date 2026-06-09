#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct tree
{
    int data;int deep;
    struct tree *left;
    struct tree *right;
}btree;
btree *first,*p,*q,*root,*r;
/*void inorder(btree *t){
    btree *stack[200], *p=t;
    int high=0;
    while(p->left!=NULL || p->right!=NULL){
    	high++;
    	inorder(p->left);
	}
	printf("%d %d\n",p->data,high);
}*/

void print(btree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->deep);
        }
        print(root->left);
        print(root->right);
    }
}


/*void inorder(btree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->left);
        print(root->right);
    }
}
*/
int depth=1;
int main(){
    int n;scanf("%d\n",&n);int num;int flag=0;
    root=(btree*)malloc(sizeof(btree));
    root->left=root->right=NULL;
    scanf("%d",&num);
    root->data=num;root->deep=1;
    p=root;
    for(int i=1;i<n;i++){
    	depth=1;
        scanf("%d",&num);
        if(p==NULL) {
        	p->data=num;
        	goto A;
		}
		if(num==root->data){
			flag=1;
		}
 B:       
        while(num>p->data || flag==1){
        	flag=0;
            if(p->right==NULL){
                p->right=(btree*)malloc(sizeof(btree));
                p->right->left=p->right->right=NULL;
                p->right->data=num;
			}
            p=p->right;p->deep=++depth;
            
        }
        while(num<p->data){
            if(p->left==NULL){
            	p->left=(btree*)malloc(sizeof(btree));
            	p->left->left=p->left->right=NULL;
            	p->left->data=num;
        	}
            p=p->left;p->deep=++depth;
            
        }
        if(p->data==num) ;
        else goto B;
    A:    
        p->data=num;
        p=root;
    }
    print(root);

   return 0;
}

