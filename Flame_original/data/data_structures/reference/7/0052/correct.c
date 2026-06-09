#include<stdio.h>
#include<stdlib.h>
struct lzy
{
	struct lzy *lp,*rp;
	int shu;
	int shen;
};
void hao(struct lzy* si)
{
	if(si->lp==NULL&&si->rp==NULL)
	{
		printf("%d %d\n",si->shu,si->shen);
		return;
	}
	if(si->lp!=NULL)
		hao(si->lp);
	if(si->rp!=NULL)
		hao(si->rp);
	return;
}
int main()
{
	int a,b,i=0,shen;
	struct lzy *gen=(struct lzy*)malloc(sizeof(struct lzy));
	struct lzy *ma;
	scanf("%d",&a);
	scanf("%d",&b);
	gen->shu=b;
	gen->lp=NULL;
	gen->rp=NULL;
	gen->shen=1;
	for(i=1;i<a;i++)
	{
		scanf("%d",&b);
		ma=gen;
		while(1)
		{
			if(b<ma->shu)
			{
				if(ma->lp==NULL)
				{
					ma->lp=(struct lzy*)malloc(sizeof(struct lzy));
					ma->lp->shu=b;
					ma->lp->lp=NULL;
					ma->lp->rp=NULL;
					ma->lp->shen=ma->shen+1;
					break;
				}
				else
				{
					ma=ma->lp;
				}
			}
			else
			{
				if(ma->rp==NULL)
				{
					ma->rp=(struct lzy*)malloc(sizeof(struct lzy));
					ma->rp->shu=b;
					ma->rp->lp=NULL;
					ma->rp->rp=NULL;
					ma->rp->shen=ma->shen+1;
					break;
				}
				else
				{
					ma=ma->rp;
				}
			}
		}
	}
	hao(gen);
	return 0;
}

