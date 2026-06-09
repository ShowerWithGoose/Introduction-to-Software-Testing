#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tree{
	int k;
	int m;
	int flag;
	struct tree *pl,*pr;
}num,*pnum;

num root;

void insert(int i)
{
	pnum pnew=(pnum)malloc(sizeof(num));
	memset(pnew,0,sizeof(num));
	pnew->pl=NULL;pnew->pr=NULL;pnew->m=2;
	pnew->k=i;
	int temp=root.k;
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
			pnew->m+=1;
			ptemp=ptemp->pl;
			temp=ptemp->k;
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
			pnew->m+=1;
			ptemp=ptemp->pr;
			temp=ptemp->k;
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
		printf("%d %d\n",root.k,root.m);
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
	int n,i,m;
	scanf("%d",&n);
	scanf("%d",&root.k);root.pl=NULL;root.pr=NULL;root.m=1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&m);
		insert(m);
	}
	scan(root);
    return 0;
}

