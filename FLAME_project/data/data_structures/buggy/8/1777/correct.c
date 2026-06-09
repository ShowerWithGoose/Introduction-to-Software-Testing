#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m;	int number;
int line[110]= {},front=0,rear=0,sum=0;
struct side
{
	int be;
	struct side*next;
};
struct point
{
	int num;
	struct side*next;
};
struct point *a[110]= {};
int ju[110]= {};
void create(int fro,int be)
{
	if(a[fro]->next==NULL)
		{
			struct side*p=(struct side*)malloc(sizeof(struct side));
			p->next=NULL;
			p->be=be;
			a[fro]->next=p;
		}
	else
		{
			struct side*pre,*found=a[fro]->next;
			while(1)
				{
					if(be<found->be)
						{
							struct side*p=(struct side*)malloc(sizeof(struct side));
							p->next=NULL;
							p->be=be;
							if(found==a[fro]->next)
								{
									p->next=found;
									a[fro]->next=p;
								}
							else
								{
									p->next=found;
									pre->next=p;
								}
						}
					if(found->next==NULL)
						{
							if(found->be<be)
								{
									struct side*p=(struct side*)malloc(sizeof(struct side));
									p->next=NULL;
									p->be=be;
									found->next=p;
								}
							break;
						}
					else
						{
							pre=found;
							found=found->next;
						}
				}
		}
}
void depthvisit(int nu)
{
	if(ju[nu]==0)
		{
			ju[nu]=1;
			printf("%d ",nu);
			int j=-1;
			struct side*pre,*found=a[nu]->next;
			while(1)
				{
					if(ju[found->be]==0)
						{
							depthvisit(found->be);
						}
					if(found->next==NULL)
						{
							break;
						}
					else
						{
							pre=found;
							found=found->next;
						}
				}
		}
}
void spreadvisit(int nu)
{
	printf("%d ",nu);
	ju[nu]=1;
	struct side*pre,*found=a[nu]->next;
	while(1)
		{
			if(ju[found->be]==0)
				{
					line[rear++]=found->be;
					sum++;
					ju[found->be]=1;
				}
			if(found->next==NULL)
				{
					break;
				}
			else
				{
					pre=found;
					found=found->next;
				}
		}
	while(sum>0)
		{
			sum--;
			spreadvisit(line[front++]);
		}
}
void deletee(int nu)
{
	struct side*pre,*found=a[nu]->next;
	while(1)
		{
				{
					struct side*pre1,*found1=a[found->be]->next;
					while(1)
						{
							if(found1->be==nu)
								{
									if(found1==a[found->be]->next)
										{
											a[found->be]->next=found1->next;
										}
									else
										{
											pre1->next=found1->next;
										}
								}
							if(found1->next==NULL)
								{
									break;
								}
							else
								{
									pre1=found1;
									found1=found1->next;
								}
						}
				}
			if(found->next==NULL)
				{
					break;
				}
			else
				{
					pre=found;
					found=found->next;
				}
		}
		a[number]=NULL;
}
int main()
{

	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		{
			struct point*p=(struct point*)malloc(sizeof(struct point));
			p->next=NULL;
			p->num=i;
			a[i]=p;
		}
	for(int i=0; i<m; i++)
		{
			int fro;
			int be;
			scanf("%d%d",&fro,&be);

			create(fro,be);
			create(be,fro);
		}
	scanf("%d",&number);
	depthvisit(0);
	printf("\n");
	for(int i=0; i<n; i++)
		ju[i]=0;
	spreadvisit(0);
	for(int i=0; i<n; i++)
		{
			line[i]= 0;
		}
	front=0,rear=0,sum=0;
	printf("\n");
	for(int i=0; i<n; i++)
		ju[i]=0;

	deletee(number);
	depthvisit(0);
	printf("\n");
	for(int i=0; i<n; i++)
		ju[i]=0;
	spreadvisit(0);



	return 0;
}


