#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int high=0;

struct tree{
	int n;
	int height;
	struct tree *left,*right;
};

struct tree *first=NULL,*r,*p,*z;
struct tree *insertBST(struct tree *p,int item);
void print(struct tree *z);

int main(){
	int n,i=0,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		r=insertBST(r,a[i]);
	}
	print(r);
	return 0;
}

void print(struct tree *z)
{
    if(z!=NULL)
    {
        if ((z->left==NULL) && (z->right==NULL))
        {
            printf("%d %d\n", z->n, z->height);
        }
        print(z->left);
        print(z->right);
    }
}

struct tree *insertBST(struct tree *p,int item){
	high++;
	if(p==NULL){
        p=(struct tree*)malloc(sizeof(struct tree));
        p->n=item;
        p->height=high;
        p->left=p->right=NULL;
        high=0;
    } 
	else if(item<p->n){
		p->left=insertBST(p->left,item);
	}
	else if(item>=p->n){
		p->right=insertBST(p->right,item);
	}
	return p;
}

