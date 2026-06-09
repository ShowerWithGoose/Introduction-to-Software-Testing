#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node btnode;
typedef struct node *btnodeptr;

int dep=1;

btnodeptr insertbst(btnodeptr p,int item){
    if(p==NULL){
        p=(btnodeptr)malloc(sizeof(btnode));
        p->data=item;
        p->left=NULL;
        p->right=NULL;
    }
    else if(item<p->data)
        p->left=insertbst(p->left,item);
    else
        p->right=insertbst(p->right,item);
    return p;
}

void inorder(btnodeptr t){
    if(t!=NULL){
    	dep++;
    	inorder(t->left);
	    if(t->left==NULL&&t->right==NULL)
        printf("%d %d\n",t->data,dep-1);
        inorder(t->right);
        dep--;
    }
}

int main(){
    int n,item,i;
    btnodeptr T=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&item);
    	T=insertbst(T,item);
	}
    inorder(T);
}

