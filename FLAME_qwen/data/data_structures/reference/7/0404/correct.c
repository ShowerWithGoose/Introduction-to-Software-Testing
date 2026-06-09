#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trees{
	int date;
    struct trees *left;
    struct trees *right;
    int depth;
}treenode,*treenodep;
int a,m,i,j,k,node;
treenodep root=NULL;
void visit(treenodep t)
{
 printf("%d %d\n",t->date,t->depth);
}
void panduan(treenodep t)
{
    if(t!=NULL){
        panduan(t->left);
        if(t->left==NULL && t->right==NULL) 
		visit(t);     
        panduan(t->right);
    }
}
void ins(treenodep *t,int value,int depth) 
{
 if(*t==NULL)
 {
  	*t=(treenodep)malloc(sizeof(treenodep));
  	(*t)->left=(*t)->right=NULL;
  	(*t)->date=value;
  	(*t)->depth=depth;
  	
 }
 else if(value<(*t)->date)
 {
	ins(&((*t)->left),value,depth+1);
 } 
 else
 {
  ins(&((*t)->right),value,depth+1);
 } 
}
int main()
{
	scanf("%d",&a);
	for(i=0;i<a;i++)
 	{
  		scanf("%d",&m);
  		ins(&root,m,1);
 	}
 panduan(root);
 return 0;
}

