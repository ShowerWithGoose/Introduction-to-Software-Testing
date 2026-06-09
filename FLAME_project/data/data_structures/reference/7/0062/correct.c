#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left,*right;
	int deep;
 };
void add(int deep,struct tree *p);
void print(struct tree *p);
struct tree *head=NULL;
struct tree *sort(int data,struct tree *p);

int main()
{
	int n,data,i,deep=1;
	struct tree *p=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		p=sort(data,p);
	
	}
	add(deep,head);
	print(head);
 	return 0;
  } 
  
  
struct tree *sort(int data,struct tree *p)
{
	if(p==NULL)
	{	
		p=(struct tree *)malloc(sizeof(struct tree));
		p->data=data;
		p->left=p->right=NULL;
	}
	else if(data>=p->data)
	{
		p->right=sort(data,p->right); 
		
	}
	else
	{
		p->left=sort(data,p->left);
	}
	if(head==NULL)
	{
		head=p;	
	}
	return p;
}

void print(struct tree *p)
{
	if(p!=NULL)
	{
		
		print(p->left);
		print(p->right);
		if(p->left==NULL&&p->right==NULL)
			printf("%d %d\n",p->data,p->deep);
	}
	
}

void add(int deep,struct tree *p)
{
	if(p!=NULL)
	{
		p->deep=deep;
		add(deep+1,p->left);
		add(deep+1,p->right);
	}
	
}





