#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max(x,y) x>y?x:y
typedef struct st{
    struct st *left,*right;
    int data;
}BTNode,*BTNodeptr;
BTNodeptr T=NULL,p=NULL,q=NULL;
BTNodeptr insertBST(BTNodeptr p,int m);
void preLEAF(BTNodeptr p);
int heightP(BTNodeptr p,int base,BTNodeptr base_node);
int main()
{
   int n,i=0,m;
   scanf("%d",&n);
   while(i<n)
   {
       scanf("%d",&m);
       T=insertBST(T,m);
       i++; 
   }
   preLEAF(T);
   return 0;
}
BTNodeptr insertBST(BTNodeptr p,int m)
{
	int layer=0;
    if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=m;
        p->left=p->right=NULL;
    }
    else if(m<p->data)
    {
    	p->left=insertBST(p->left,m);
	}
    else if(m>=p->data){
    	p->right=insertBST(p->right,m);
	}
    return p;
}
int heightP(BTNodeptr p,int base,BTNodeptr base_node)
{
	if(base_node==NULL) return -1;
	if(p==base_node) return base;
	int heightL,heightR;
	heightL=heightP(p,base+1,base_node->left);
	if(heightL!=-1) return heightL;
	heightR=heightP(p,base+1,base_node->right);
	if(heightR!=-1) return heightR;
	return -1;
}
void preLEAF(BTNodeptr p)
{
    if(p!=NULL)
    {
        if(p->left==NULL&&p->right==NULL)
         printf("%d %d\n",p->data,heightP(p,1,T));
        preLEAF(p->left);
        preLEAF(p->right);
    }
}

