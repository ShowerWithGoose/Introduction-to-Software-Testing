#include <stdio.h>
#include <stdlib.h>
struct olo{
	int cot;
	int hight;
	struct olo *lk;
	struct olo *rk;
};
struct olo *w,*head,*p;
void insert(struct olo *a,struct olo *b)
{
	if(a==NULL)
	{
		a=b;
		printf("%d",a->cot);
	}
	else
	{
		if(a->cot>b->cot)
		insert(a->lk,b);
		else
		insert(a->rk,b);
	}
}
void search(struct olo *a)
{
	if(a!=NULL)
	{
		if(a->lk==NULL&&a->rk==NULL)
			printf("%d %d\n",a->cot,a->hight);
		search(a->lk);
		search(a->rk);
	}
}
void des(struct olo* a)
{
	if(a!=NULL)
	{
		des(a->lk);
		des(a->rk);
		free(a);
	}
}

int main()
{
	int all,h,buf;
	scanf("%d",&all);
	head=NULL;
loop:	while(all!=0)
	{
		p=head;
		h=1;
		scanf("%d",&buf);
		if(p==NULL)
		{
			head=(struct olo*)malloc(sizeof(struct olo));
			head->cot=buf;
			head->hight=1;
			head->lk=NULL;
			head->rk=NULL;
			all--;
		}
		else
		{
			while(1)
			{
				if(buf<p->cot)
				{
					if(p->lk!=NULL)
					{
						p=p->lk;
						h++;
					}
					else
					{
						p->lk=(struct olo*)malloc(sizeof(struct olo));
						p->lk->cot=buf;
						p->lk->hight=h+1;
						p->lk->lk=NULL;
						p->lk->rk=NULL;
						all--;
						goto loop;
					}
				}
				else
				{
					if(p->rk!=NULL)
					{
						p=p->rk;
						h++;
					}
					else
					{
						p->rk=(struct olo*)malloc(sizeof(struct olo));
						p->rk->cot=buf;
						p->rk->hight=h+1;
						p->rk->lk=NULL;
						p->rk->rk=NULL;
						all--;
						goto loop;
					}
				}
			}
		}
	}
	//printf("%d",head->cot); 
	search(head);
	des(head);
	return 0;
}

