#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int n,x;

void sca()
{
	scanf("%d",&x);
}

void des()
{
	scanf("%d",&n);
}

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
struct tree{
	struct tree *left;
	struct tree *right;
	int num;
};
void tree_print(struct tree *root){
	struct tree *p1,*p2;
	p1=root;
	while(p1!=NULL){
		printf("%d",p1->num);
		p1=p1->left;
	}
}
void print(struct tree *root,int level){
	struct tree *p1,*p2;
	p1=root;
	if(p1->left==NULL&&p1->right==NULL){
		printf("%d %d\n",p1->num,level);
	}else{
		if(p1->left!=NULL){
			print(p1->left,level+1);
		}
		if(p1->right!=NULL){
			print(p1->right,level+1);
		}
	}
	
}
int main()
{
	des();
	//scanf("%d",&n);
	struct tree *root=calloc(1,sizeof(struct tree));
	struct tree *p1,*p2;
	scanf("%d",&root->num);
	root->left=NULL;
	root->right=NULL;
	int i,j;
	for(i=0;i<n-1;i++){
		p1=root;
		sca();
		//scanf("%d",&x);
		while(1){
			if(x>=p1->num){
				if(p1->right!=NULL){
					p1=p1->right;
				}else{
					break;
				}
			}else{
				if(p1->left!=NULL){
					p1=p1->left; 
				}else{
					break;
				}
				
			}
		}
		if(x>=p1->num){
			p2=(struct tree*)calloc(1,sizeof(struct tree));
			p2->num=x;
			p1->right=p2;
		}else{
			p2=(struct tree*)calloc(1,sizeof(struct tree));
			p2->num=x;
			p1->left=p2;
		}
	}
	print(root,1);
	return 0;
}




