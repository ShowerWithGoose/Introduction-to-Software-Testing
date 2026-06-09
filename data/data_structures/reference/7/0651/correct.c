#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int data;
	struct node *l,*r;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr shuru(BTNodeptr p,int x)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=x;
		p->l=NULL;
		p->r=NULL;
	}
	else if(p->data>x)
	{
		p->l=shuru(p->l,x);
	} 
	else
	{
	    p->r=shuru(p->r,x);
	}
	return p; 
}
void printNode(BTNodeptr p,int hight)
{
	if(p->l!=NULL) 
            printNode(p->l,hight+1); 
     if(p->r!=NULL) 
            printNode(p->r,hight+1); 
      if(p->l==NULL && p->r==NULL) 
             printf("%d %d\n",p->data,hight); 
}
int main()
{
    int n,i=0,a;
	scanf("%d",&n);
	
	BTNodeptr first=NULL;
	while(i<n)
	{
		scanf("%d",&a);
		first=shuru(first,a);
		i++;
	}
	printNode(first,1);    
 return 0;		
}

