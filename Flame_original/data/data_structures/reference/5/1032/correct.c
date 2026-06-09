#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dxs
{
	int xi;
	int zhi;
	struct dxs* next;
};

struct dxs *head3,*sh3;


void multi(struct dxs* p1,struct dxs* p2);
void sort(struct dxs*q);
void bubble(struct dxs*r);


int main()
{
	struct dxs *sh1,*sh2,*head1,*head2;
	int i,a,b;
	
	head1= NULL;
	head2= NULL;
	
	for(i=0; ;i++)
	{
		scanf("%d %d",&a,&b);
		if(head1==NULL)
				head1=sh1=(struct dxs*)malloc(sizeof(struct dxs));
			else
			{
				sh1->next=(struct dxs*)malloc(sizeof(struct dxs));
				sh1=sh1->next;
			}
		sh1->xi = a;
		sh1->zhi = b;
	
		
		if(getchar()=='\n')
		{
			sh1->next=NULL;
			break;
		}
		
			
		
		
	}
	
	for(i=0; ;i++)
	{
		scanf("%d %d",&a,&b);
		if(head2==NULL)
				head2=sh2=(struct dxs*)malloc(sizeof(struct dxs));
			else
			{
				sh2->next=(struct dxs*)malloc(sizeof(struct dxs));
				sh2=sh2->next;
			}
		sh2->xi = a;
		sh2->zhi = b;
		
		
		if(getchar()=='\n')
		{
			sh2->next=NULL;
				break;
		}
		
		
		
	}//输入多项式存入链表中 
	
	
	multi(head1,head2);//乘法 
	sort(head3);//合并同类项； 
	bubble(head3);//排序； 
	
	
   while(head3!=NULL)
   {
   		if(head3->xi!=0)
		printf("%d %d ",head3->xi,head3->zhi);
   		
		head3=head3->next;

   }
	
	
		
	return 0;
}

void multi(struct dxs* p1,struct dxs* p2)
{
	head3= NULL;
	struct dxs*tem = p2;
	
	
	
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			if(head3==NULL)
				head3=sh3=(struct dxs*)malloc(sizeof(struct dxs));
			else
			{
				sh3->next=(struct dxs*)malloc(sizeof(struct dxs));
				sh3=sh3->next;
			}
			sh3->xi=p1->xi*p2->xi;
			sh3->zhi=p1->zhi+p2->zhi;
			
			
			
			p2=p2->next;
			

		}
		
		p1=p1->next;
		p2=tem;
	}
	
	
	sh3->next = NULL;
	
}

void sort(struct dxs*q)
{
	int i;
	struct dxs *tem;
	while(q!=NULL)
	{
		tem=q->next;
		while(tem!=NULL)
		{
			if(q->zhi==tem->zhi)
			{
				q->xi+=tem->xi;
				tem->xi=0;
				tem->zhi=-1;
			}
			tem=tem->next;
		}
		q=q->next;
	}
}

void bubble(struct dxs*r)
{
	int temxi,temzhi;
	int i,j;
	struct dxs *tem;
	int flag=1;
	while(flag)
	{
		tem=r;
		flag=0;
		while(tem!=NULL)
		{
		    if((tem->next!=NULL)&&(tem->next->zhi)>(tem->zhi))
		    {
		    	temxi=tem->next->xi;
		    	tem->next->xi=tem->xi;
		    	tem->xi=temxi;
		    
		    	temzhi=tem->next->zhi;
		    	tem->next->zhi=tem->zhi;
		    	tem->zhi=temzhi;
		    	
		    	flag=1;
			}
			tem=tem->next;
		}
		
		
	}

}



