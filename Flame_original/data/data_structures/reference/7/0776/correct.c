#include<stdio.h>
#include<string.h> 
#include<stdlib.h>

struct Trees{
	int number;
	struct Trees *left;
	struct Trees *right;
	int height;
};
typedef struct Trees t,*tptr;

int n,num;

void preorder(tptr p)
{
	if(p!=NULL)
	{
		if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->number,p->height);
		preorder(p->left);
		preorder(p->right);
	}
	else return;
}

int main()
{
	scanf("%d",&n);
//	printf("n=%d\n",n);
	tptr head=(tptr)malloc(sizeof(t));
	head->height=0;
	head->left=NULL;
	head->right=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
//		printf("num%d=%d\n",i,num);
		tptr p=(tptr)malloc(sizeof(t));
		p->number=num;
		p->left=NULL;
		p->right=NULL;
		if(i==0)
		{
			p->height=1;
			head->left=p;
			continue;
		}
		else
		{
			tptr q=(tptr)malloc(sizeof(t));
			q=head->left;
			while(((q->left==NULL&&num<q->number)||(q->right==NULL&&num>=q->number))==0)
			{
//				printf("%d\n",~((q->left==NULL&&num<q->number)||(q->right==NULL&&num>q->number)));
				if(num>=q->number) q=q->right;
				else q=q->left;
			}
			tptr k=(tptr)malloc(sizeof(t));
			if(num<q->number) q->left=k;
			else q->right=k;
			k->number=num;
			k->height=q->height+1;
			k->left=NULL;
			k->right=NULL;
		}
	}
	preorder(head);
	return 0;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/

