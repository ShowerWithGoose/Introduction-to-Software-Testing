#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int an,n;
	struct node*link;
};
void DestroyList(struct node *head)  
{  
    struct node *p;  
    if(head==NULL)  
        return ;  
    while(head)  
    {  
        p=head->link;  
        free(head);  
        head=p;  
    } 
}  
int cmp(const void*a,const void*b)
{
	int *c = (int *)a;
    int *d = (int *)b;
    return *d-*c;
}
int main()
{
	struct node*list1=NULL,*list2=NULL,*p,*q;
	int i,j,x=0,y=0,fc[66666][2];
	do
	{
		q=(struct node*)malloc(sizeof(struct node*));
		scanf("%d%d",&(q->an),&(q->n));
		q->link=NULL;
		if(list1==NULL)
			list1=q;
		else
			p->link=q;
		p=q;
		x++;
	}while(getchar()!='\n');
	do
	{
		q=(struct node*)malloc(sizeof(struct node*));
		scanf("%d%d",&(q->an),&(q->n));
		q->link=NULL;
		if(list2==NULL)
			list2=q;
		else
			p->link=q;
		p=q;
		y++;
	}while(getchar()!='\n');
	
	for(p=list1,i=0;p!=NULL;p=p->link)
		for(q=list2;q!=NULL;q=q->link)
		{
			x=(p->an)*(q->an);y=(p->n)+(q->n);
			for(j=0;fc[j][1]!=0;j++)
				if(fc[j][0]==y)
				{
					fc[j][1]+=x;
					break;
				}
			if(fc[j][1]==0)
			{
				fc[j][1]=x;fc[j][0]=y;i++;
			}
		}
	qsort(fc,i,sizeof(fc[0]),cmp);
	for(j=0;j<i;j++)
		printf("%d %d ",fc[j][1],fc[j][0]);
	DestroyList(list1);
	DestroyList(list2);
	return 0;
}

