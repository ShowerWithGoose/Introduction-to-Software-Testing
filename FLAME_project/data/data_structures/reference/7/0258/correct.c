#include<stdio.h>
#include<stdlib.h>
typedef struct _tree{
	int data,deepth;
	struct _tree *left,*light;
}tree,*Ptree;
Ptree insert(Ptree p,int num);
Ptree root=NULL;
void Leaf(Ptree b);
int height=1;
int main(){
	int n;
	scanf("%d",&n);
	int i,item;
	for(i=0;i<n;i++) {
		scanf("%d",&item);
		root=insert(root,item);
		height=1;
	}
	Leaf(root);
	return 0;
}
Ptree insert(Ptree p,int num){
	if(p==NULL) {
		p=(Ptree)malloc(sizeof(tree));
		p->data=num;
		p->left=NULL;
		p->light=NULL;
		p->deepth=height++; 
	}
	else if(num<p->data) {
		height++;
		p->left=insert(p->left,num);
	}
	else {
		height++;
		p->light=insert(p->light,num);
	}
	return p;
 }
 void Leaf(Ptree b)
 {
 	if (b!=NULL) 
 	{
 		if (b->left==NULL && b->light==NULL) 
 			printf("%d %d\n",b->data,b->deepth);	//访问叶子节点
 		Leaf(b->left);		//输出左子树中的叶子节点
 		Leaf(b->light);		//输出右子树中的叶子节点
 	} }


