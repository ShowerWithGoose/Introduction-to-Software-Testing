#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct tree{
	int a;
	struct tree *rchild,*lchild;
}*root,*p;
void printhight(struct tree *r,int hight){
	if(r->lchild!=NULL)
	printhight(r->lchild,hight+1);
	if(r->lchild==NULL&&r->rchild==NULL)
	printf("%d %d\n",r->a,hight);
	if(r->rchild!=NULL)
	printhight(r->rchild,hight+1);
}
int main(){
	int n,i,data;
	scanf("%d",&n);
	root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&data);
		if(root==NULL)
		{
			root=(struct tree*)malloc(sizeof(struct tree));
			root->a=data;
			root->rchild=NULL;
			root->lchild=NULL;
		}
		else{
			p=root;
			while(1){
				if(data<p->a)
				{
					if(p->lchild==NULL)
					{
						p->lchild=(struct tree*)malloc(sizeof(struct tree));
						p=p->lchild;
						break;
					}
					else
					p=p->lchild;
				}
				else
				{
					if(p->rchild==NULL){
						p->rchild=(struct tree*)malloc(sizeof(struct tree));
						p=p->rchild;
						break;
					}
					else
					p=p->rchild;
				}
			}
			p->a=data;
			p->lchild=NULL;
			p->rchild=NULL;
		}
	}
	printhight(root,1);
	return 0;
}



