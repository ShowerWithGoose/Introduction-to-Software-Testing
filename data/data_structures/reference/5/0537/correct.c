#include<stdio.h>
#include<stdlib.h>
struct node
{
	int xishu;
	int zhishu;
	struct node *next; 
 } ;
 void sort(struct node *head)
 {
 	struct node *front,*rear;
 	front=head;
 	rear=NULL;
 	int tmp1,tmp2;
 	while(front!=rear)
 	{
 		while(front->next!=rear)
 		{
 		  if(front->zhishu<front->next->zhishu)
	      {
	   	    tmp1=front->xishu;
	   	    front->xishu=front->next->xishu;
	   	    front->next->xishu=tmp1;
	   	    tmp2=front->zhishu;
	   	    front->zhishu=front->next->zhishu;
	   	    front->next->zhishu=tmp2;
	      }	
		  front=front->next;	
		}
		rear=front;
		front=head;
	 }
 }
int main()
{
  int xi1,zhi1,xi2,zhi2;
  char c1,c2;
  struct node *head1=NULL,*head2=NULL,*head=NULL,*p1=NULL,*p2=NULL,*q1=NULL,*q2=NULL,*r1=NULL,*r2=NULL,*pp=NULL,*qq=NULL;
  while(c1!='\n')
  {
  	scanf("%d%d%c",&xi1,&zhi1,&c1);
  	q1=(struct node*)malloc(sizeof(struct node));
  	q1->xishu=xi1;
  	q1->zhishu=zhi1;
  	q1->next=NULL;
  	if(head1==NULL)
  	head1=p1=q1;
  	else
  	{
  	  p1->next=q1;
	  p1=p1->next;	
	}
  }
  while(c2!='\n')
  {
  	scanf("%d%d%c",&xi2,&zhi2,&c2);
  	q2=(struct node*)malloc(sizeof(struct node));
  	q2->xishu=xi2;
  	q2->zhishu=zhi2;
  	q2->next=NULL;
  	if(head2==NULL)
  	head2=p2=q2;
  	else
  	{
  	  p2->next=q2;
	  p2=p2->next;	
	}
  }
  for(p1=head1;p1!=NULL;p1=p1->next)
  {
  	for(p2=head2;p2!=NULL;p2=p2->next)
  	{
  	  qq=(struct node*)malloc(sizeof(struct node));
	  qq->xishu=p1->xishu*p2->xishu;
	  qq->zhishu=p1->zhishu+p2->zhishu;
	  if(head==NULL)
	  {
	  	head=pp=qq;
	  }
	  else
	  {
	  	pp->next=qq;
	  	pp=pp->next;
	  }
	}
  }
  //pp->next=NULL;
  for(pp=head;pp!=NULL;pp=pp->next)
  {
  	r2=pp;
  	for(r1=pp->next;r1!=NULL;r1=r1->next)
  	{
  		if(r1->zhishu==pp->zhishu)
  		{
  		  pp->xishu+=r1->xishu;
		  r2->next=r1->next;
		  free(r1);
		  r1=r2->next;
		}
		r2=r1;
	}
  }
  sort(head);
  for(pp=head;pp!=NULL;pp=pp->next)
  printf("%d %d ",pp->xishu,pp->zhishu);
  return 0;
}

