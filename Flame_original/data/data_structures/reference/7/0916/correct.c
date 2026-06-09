#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
    int a;
    struct TreeNode *L;
    struct TreeNode *R;
    int D;
}Tree,*T;
void F(T *e,int c,int D) 
{
	if(*e==NULL)
	{
		*e=(T)malloc(sizeof(T));
		(*e)->L=(*e)->R=NULL;
		(*e)->a=c;
		(*e)->D=D;
	}
	else if(c<(*e)->a)
	{
		F(&((*e)->L),c,D+1);
	} 
	else
	{
		F(&((*e)->R),c,D+1);
	} 
}
void G(T e)
{
    if(e!=NULL){
        G(e->L);
        if(e->L==NULL && e->R==NULL)
			printf("%d %d\n",e->a,e->D);   
        G(e->R);
    }
}
int main()
{	
    int b,i,n;
    T g=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b);
		F(&g,b,1);
	}
	G(g);
	return 0;
}






