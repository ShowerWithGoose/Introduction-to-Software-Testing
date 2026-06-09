#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
struct stack{
	int num;
	struct stack  *lnext,*rnext;
};
struct stack *p,*q,*head,*r;
struct stack *stackin(int a);
int count=0;
struct stack *stackout(int x);

		
int main()
{
	struct stack *L;
	{
		head=(struct stack*)malloc(sizeof(struct stack));
		head->lnext=NULL;
		head->rnext=NULL;
		q=head;
		head->num=0;
	}
	while(1){
		int sit;
		int a;
		scanf("%d",&sit);
		//printf("%d\n",sit);
		if(sit==1){
			scanf("%d",&a);
		//	printf("%d\n",a);
			stackin(a);
		}
		else if(sit==0){
			stackout(sit);
		}
		else if(sit==-1){
			break;
		}
	}

	return 0;
}
struct stack  *stackin(int a){
//	printf("5");
	if(head->num==0){
		head->num=a;
		q=head;
		//printf("headÒÑ½¨Á¢\n");
	}
	else{
		p=(struct stack*)malloc(sizeof(struct stack));
	q->rnext=p;
	p->lnext=q;
	p->rnext=NULL;
	p->num=a;
	q=p;
	}
	
	//printf("q=%d\n",q->num);
	count++;
//	printf("q%d is ready\n",count);
	return head;
}
struct stack *stackout(int x){
	if((q==head)&&(head->num!=0)){
		printf("%d ",q->num);
		head->num=0;
		
		
	}
	else if((q==head)&&(head->num==0)){
	printf("error ");
	}
	else{
		printf("%d ",q->num);
		q=q->lnext;
		
	}
	return head;
}


