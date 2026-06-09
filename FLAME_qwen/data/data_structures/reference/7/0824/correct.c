#include <stdio.h>
#include <stdlib.h>

/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/
struct tnode{
	int data;
	struct tnode *left,*right;
	int dep,l,r;
}; 
typedef struct tnode Bstn, *Bstnptr;
int tmp;

Bstnptr insertBstn(Bstnptr p,int data);
void inorder(Bstnptr t);



int main()
{
	int i,n,item;
	char c;
	Bstnptr root = NULL;
	scanf("%d",&n);
//	while(c = getchar(),c<'0')
//		;
//	ungetc(c,stdin);
	for(i=0;i<n;i++)
	{
		tmp = 0;
		scanf("%d",&item);
		root = insertBstn(root,item);
	}
	inorder(root);
	return 0;
}

void inorder(Bstnptr t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->l == 0 &&t->r == 0)
		{
			printf("%d %d\n",t->data,t->dep);
		}
		inorder(t->right);
	}
	return;
}


Bstnptr insertBstn(Bstnptr p,int data)
{
	tmp++;
	if(p == NULL)
	{
		p = (Bstnptr)malloc(sizeof(Bstn));
		p->data = data;
		p->l = p->r = 0;
		p->dep = tmp;
		p->left = p->right = NULL;
		
	}
	else if(data >= p->data)
	{
		//printf("%d %d %d\n",p->data,p->dep,p->deg);
		p->r = 1;
		p->right = insertBstn(p->right,data);
		
	}
	else if(data < p->data)
	{
		p->l = 1;
		p->left = insertBstn(p->left,data);
	}
	
	return p;
}

