#include<stdio.h>
#include<stdlib.h>
struct multi{
	int an;
	int n;
	struct multi *next;
};
void add(struct multi *result,struct multi *x,struct multi *z)
{
	struct multi *current3;
	current3=result;
	while(current3!=NULL)
	{
		if(current3->n==x->n+z->n)
		{
			current3->an+=x->an*z->an;
			break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
			
		}
		current3=current3->next;
	}
}
int main()
{
	struct multi *para1=NULL,*para2=NULL,*result=NULL;
	struct multi *prev,*x,*z,*current,*temp;
	char ch='o';
	int sign;
	while(ch!='\n')
	{
		x=(struct multi*)malloc(sizeof(struct multi));
		if(para1==NULL) para1=x;
		else prev->next=x;
		x->next=NULL;
		scanf("%d %d",&x->an,&x->n);
		ch=getchar();
		prev=x;	 
	}
	ch='o';
		while(ch!='\n')
	{
		z=(struct multi*)malloc(sizeof(struct multi));
		if(para2==NULL) para2=z;
		else prev->next=z;
		z->next=NULL;
		scanf("%d %d",&z->an,&z->n);
		ch=getchar();
		prev=z;	 
	}
	x=para1;
	z=para2;
	while(z!=NULL)
	{
		while(x!=NULL)
		{
			struct multi *current3;
			current3=result;
			sign=1;
			while(current3!=NULL)
			{
				if(current3->n==x->n+z->n) sign=0;
				current3=current3->next;
			}
		if(sign)
		{
			current=(struct multi*)malloc(sizeof(struct multi));
			if(result==NULL) result=current;
			else prev->next=current;
			current->next=NULL;
			current->n=x->n+z->n;
			current->an=x->an*z->an;
			prev=current;
		}
		else
		{
			add(result,x,z);
		}
		x=x->next;
	}
	z=z->next;
	x=para1;
	}
	current=result;
	int maxn,maxan;
	while(1)
	{
	 maxn=-1;
		while(current!=NULL)
	{
		if(maxn<current->n)
		{
			maxn=current->n;
			maxan=current->an;
			temp=current;
		}
		current=current->next;
	}
		if(maxn==-1) break;
		printf("%d %d ",maxan,maxn);
		temp->n=-1;
		current=result;
	}	
 } 

