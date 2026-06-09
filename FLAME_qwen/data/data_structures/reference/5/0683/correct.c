#include<stdio.h>
struct multi{
	int a;
	int n;
	struct multi *next;
}x1,x2,x3,x4[10000],*p,*q,*z;
int main(){
	int sum1=0,sum2=0,i=0;
	scanf("%d%d",&x1.a,&x1.n);
	p=&x1;
	while(getchar()!='\n'){
		scanf("%d%d",&x4[i].a,&x4[i].n);
		p->next=&x4[i];
		i++;
		p=p->next;
	}
	p->next=NULL;
	scanf("%d%d",&x2.a,&x2.n);
	p=&x2;
	while(scanf("%d%d",&x4[i].a,&x4[i].n)!=EOF){
		p->next=&x4[i];
		p=p->next;
		i++;
	}
	p->next=NULL;
	x3.a=(x1.a)*(x2.a);
	x3.n=(x1.n)+(x2.n);
	x3.next=NULL;
	z=&x3;
	for(p=&x2;p!=NULL;p=p->next){
		for(q=&x1;q!=NULL;q=q->next){
			sum1=(p->a)*(q->a);
			sum2=(p->n)+(q->n);
			while(z->next!=NULL&&sum2<=(z->next->n)){
				z=z->next;
			}
			if(sum2==(z->n)){
				(z->a)+=sum1;
			}else{
				x4[i].a=sum1;
				x4[i].n=sum2;
				x4[i].next=z->next;
				z->next=&x4[i];
				i++;
			}
			z=&x3;
		}
	};
	x3.a-=(x1.a)*(x2.a);
	for(z=&x3;z!=NULL;z=z->next){
		printf("%d %d ",z->a,z->n);
	}
	return 0;
}

