#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct node{
	int coe;
	int pow;
	struct node*next;
};
struct num{
	int coe;
	int pow;
};
struct num num[1000];
int cmp(const void*_p1,const void *_p2)
{
	struct num*a=(struct num*)_p1;
	struct num*b=(struct num*)_p2;
	return b->pow-a->pow;
}
int main()
{
	int a,b,n=0,i,j;
	char c;
	struct node*first1,*first2,*p,*t,*first3,*r,*ptr,*ptr1;
	first1=p=(struct node*)malloc(sizeof(struct node));
	first2=t=(struct node*)malloc(sizeof(struct node));
	do{
		scanf("%d%d%c",&a,&b,&c);
		n++;
		p->coe=a;
		p->pow=b;
		p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
	}while(c!='\n');
	int lp=n;
	p=NULL;
    n=0;
	do{
		scanf("%d%d%c",&a,&b,&c);
		n++;
		t->coe=a;
		t->pow=b;
		t->next=(struct node*)malloc(sizeof(struct node));
		t=t->next;
	}while(c!='\n');
	t!=NULL;
	int lt=n;
	
	first3=r=(struct node*)malloc(sizeof(struct node));
	int lr=lt*lp;
	for(p=first1,i=0;i<lp;p=p->next,i++){
		for(t=first2,j=0;j<lt;t=t->next,j++){
			r->coe=(p->coe)*(t->coe);
			r->pow=(p->pow)+(t->pow);
			r->next=(struct node*)malloc(sizeof(struct node));
			r=r->next;
		}
	}
	r=NULL;
	for(r=first3,i=0;i<lr;r=r->next,i++)
	{
		for(ptr=r->next,ptr1=r,j=i+1;j<lr;ptr=ptr->next,j++)
		{
			if(r->pow==ptr->pow){
				lr--;
				r->coe+=ptr->coe;
				ptr=ptr1->next;
				ptr1->next=ptr1->next->next;
				free(ptr); 
				ptr=ptr1;
			}
			else
			ptr1=ptr1->next;
		}
	}
	for(i=0,r=first3;i<lr;i++,r=r->next){
		num[i].coe =r->coe;
		num[i].pow =r->pow;
	}
	num[i].coe =num[i].pow ='\0';
	qsort(num,lr,sizeof(struct num),cmp);
	for(i=0;i<lr;i++)
	{
		printf("%d %d ",num[i].coe,num[i].pow );
	 } 
	 return 0;
	
}


