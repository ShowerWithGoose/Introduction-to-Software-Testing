#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i=0;

struct tree{
	int m;
	int height;
	struct tree *left,*right;
};

struct tree *first=NULL,*root,*z,*p;
struct tree *insertBST(struct tree *z,int item);
void print(struct tree *p);

int main(){
	int m,i=0,num[100];
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&num[i]);
		root=insertBST(root,num[i]);
	}
	print(root);
	return 0;
}

void print(struct tree *p)
{
    if(p!=NULL)
    {
        if ((p->left==NULL) && (p->right==NULL))
        {
            printf("%d %d\n", p->m, p->height);
        }
        print(p->left);
        print(p->right);
    }
}

struct tree *insertBST(struct tree *z,int item){
	i++;
	if(z==NULL){
        z=(struct tree*)malloc(sizeof(struct tree));
        z->m=item;
        z->height=i;
        z->left=z->right=NULL;
        i=0;
    } 
	else if(item<z->m){
		z->left=insertBST(z->left,item);
	}
	else if(item>=z->m){
		z->right=insertBST(z->right,item);
	}
	return z;
}

