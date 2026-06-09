#include<stdio.h>
#include<stdlib.h>
struct multi{
	int an;
	int n;
	struct multi *next;
};
void add(struct multi *head,struct multi *current1,struct multi *current2)
{
	struct multi *current3;
	current3=head;
	while(current3!=NULL)
	{
		if(current3->n==current1->n+current2->n)
		{
			current3->an+=current1->an*current2->an;
			break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
			
		}
		current3=current3->next;
	}
}
int main()
{
	struct multi *head1=NULL,*head2=NULL,*head=NULL;
	struct multi *prev,*current1,*current2,*current,*temp;
	char ch='o';
	int sign;
	while(ch!='\n')
	{
		current1=(struct multi*)malloc(sizeof(struct multi));
		if(head1==NULL) head1=current1;
		else prev->next=current1;
		current1->next=NULL;
		scanf("%d %d",&current1->an,&current1->n);
		ch=getchar();
		prev=current1;	 
	}
	ch='o';
		while(ch!='\n')
	{
		current2=(struct multi*)malloc(sizeof(struct multi));
		if(head2==NULL) head2=current2;
		else prev->next=current2;
		current2->next=NULL;
		scanf("%d %d",&current2->an,&current2->n);
		ch=getchar();
		prev=current2;	 
	}
	current1=head1;
	current2=head2;
	while(current2!=NULL)
	{
		while(current1!=NULL)
		{
			struct multi *current3;
			current3=head;
			sign=1;
			while(current3!=NULL)
			{
				if(current3->n==current1->n+current2->n) sign=0;
				current3=current3->next;
			}
		if(sign)
		{
			current=(struct multi*)malloc(sizeof(struct multi));
			if(head==NULL) head=current;
			else prev->next=current;
			current->next=NULL;
			current->n=current1->n+current2->n;
			current->an=current1->an*current2->an;
			prev=current;
		}
		else
		{
			add(head,current1,current2);
		}
		current1=current1->next;
	}
	current2=current2->next;
	current1=head1;
	}
	current=head;
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
		current=head;
	}	
 } 

