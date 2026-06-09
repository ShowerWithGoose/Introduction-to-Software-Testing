#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tree{
	int n;
	int k;
	int flag;
	struct tree *pl,*pr;
}num,*pnum;

num root;

void insert(int i)
{
	pnum pnew=(pnum)malloc(sizeof(num));
	memset(pnew,0,sizeof(num));
	pnew->pl=NULL;pnew->pr=NULL;pnew->k=2;
	pnew->n=i;
	int temp=root.n;
	pnum ptemp=&root;
	while(1)
	{
	if(i<temp)
	{
		if(ptemp->pl==NULL)
		{
			ptemp->pl=pnew;
			break;
		}else
		{
			pnew->k+=1;
			ptemp=ptemp->pl;
			temp=ptemp->n;
			continue;
		}
	}
	if(i>=temp)
	{
		if(ptemp->pr==NULL)
		{
			ptemp->pr=pnew;
			break;
		}else
		{
			pnew->k+=1;
			ptemp=ptemp->pr;
			temp=ptemp->n;
			continue;
		}
	}
	}
	return;
}

void scan(num root)
{
	if(root.pl==NULL&&root.pr==NULL)
	{
		printf("%d %d\n",root.n,root.k);
		return;
	}
	if(root.pl!=NULL)
	{
		scan(*root.pl);
	}
	if(root.pr!=NULL)
	{
		scan(*root.pr);
	}
}

int main()
{
	int m,i,k;
	scanf("%d",&m);
	scanf("%d",&root.n);root.pl=NULL;root.pr=NULL;root.k=1;
	for(i=0;i<m-1;i++)
	{
		scanf("%d",&k);
		insert(k);
	}
	scan(root);
    return 0;
}

