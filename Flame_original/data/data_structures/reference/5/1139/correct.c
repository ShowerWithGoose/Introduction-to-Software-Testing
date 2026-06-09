#include<stdio.h>
#include<stdlib.h>
struct list {
	int a;
	int point;
	struct list *next;
};
int main(){
	int i,j,len_1=0,len_2=0,len_3;
	int m,n,middle;
	char c;
	struct list *first_1=NULL,*first_2=NULL,*first_3=NULL,*p,*q,*o;
	do{
		scanf("%d%d",&m,&n);
		q=(struct list*)malloc(sizeof(struct list));
		q->next=NULL;
		if(first_1==NULL)
		first_1=p=q;
		else {
			p->next=q;
			p=p->next;
		}
		q->a=m,q->point=n;
		len_1++;
	}while(c=getchar()!='\n');
	
	do{
		scanf("%d%d",&m,&n);
		q=(struct list*)malloc(sizeof(struct list));
		q->next=NULL;
		if(first_2==NULL)
		first_2=p=q;
		else {
			p->next=q;
			p=p->next;
		}
		q->a=m;q->point=n;
		len_2++;
	}while(c=getchar()!='\n'); 
	//printf("%d %d\n",len_1,len_2);
	len_3=len_2*len_1;
	for(i=0;i<len_3;i++){
		q=(struct list*)malloc(sizeof(struct list));
		q->next=NULL;
		if(first_3==NULL)first_3=p=q;
		else{
			p->next=q;
			p=p->next;
		}
		p->a=i;
	}
	
	o=first_3;
	//printf("%d %d\n",len_1,len_2);
	for(p=first_1,i=0;i<len_1;i++,p=p->next){
		for(q=first_2,j=0;j<len_2;j++,q=q->next){
			(o->a)=(p->a)*(q->a);
			(o->point)=(p->point)+(q->point);
			//printf("%d %d\n",o->a,o->point);
			o=o->next;
		}
	}
	//printf("1");
	for(o=first_3;o!=NULL;o=o->next){
		for(p=o;p!=NULL;p=p->next){
			if(p->next==NULL)break;
			if(p->next->point==o->point){
				o->a+=p->next->a;
				q=p->next;
				p->next=p->next->next;
				free(q);
			}
		}
	}
	for(o=first_3;o!=NULL;o=o->next){
		for(p=o;p!=NULL;p=p->next){
			if(o->point<p->point){
				middle=o->point;
				o->point=p->point;
				p->point=middle;
				middle=o->a;
				o->a=p->a;
				p->a=middle;
			}
		}
	}
	//printf("1");
	for(o=first_3;o!=NULL;o=o->next){
		if(o->a!=0)
		printf("%d %d ",o->a,o->point);
	}
	return 0;
}



