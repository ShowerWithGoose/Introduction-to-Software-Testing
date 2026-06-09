#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Xiang{
	int xi;
	int zhi;
	struct Xiang *next;
}*first1=NULL,*first2=NULL,*first3=NULL,*p,*q,*r,*k,*find;
int main(){
	int i,j,m,f1=1,f2=1,f3=0;
	char t;
	p=(struct Xiang *)malloc(sizeof(struct Xiang));
	p->next=NULL;
	scanf("%d %d",&p->xi,&p->zhi);
	first1=q=p;
	t=getchar();
	while(t!='\n'){
		p=(struct Xiang *)malloc(sizeof(struct Xiang));
		p->next=NULL;
		scanf("%d%d",&p->xi,&p->zhi);
		q->next=p;
		q=q->next;
		f1++;
		t=getchar();
	}
	p=(struct Xiang *)malloc(sizeof(struct Xiang));
	p->next=NULL;
	scanf("%d%d",&p->xi,&p->zhi);
	first2=q=p;
	t=getchar();
	while(t!='\n'){
		p=(struct Xiang *)malloc(sizeof(struct Xiang));
		p->next=NULL;
		scanf("%d%d",&p->xi,&p->zhi);
		q->next=p;
    	q=q->next;
		f2++;
		t=getchar();
	}
	p=first1;
	q=first2;

	for(i=1;i<=f1;i++){
		for(j=1;j<=f2;j++){
			r=(struct Xiang*)malloc(sizeof(struct Xiang));
			r->xi=(p->xi)*(q->xi);
			r->zhi=(p->zhi)+(q->zhi);
			r->next=NULL;
			if(first3==NULL){
				first3=k=r;
				f3++;
			}
			else{
				find=first3;
				for(m=1;m<=f3;m++){
					if(r->zhi==find->zhi){
						find->xi+=r->xi;
						free(r);
						break;
					}
					find=find->next;
				}
				if(m==f3+1){
					k->next=r;
					k=k->next;
					f3++;
				}
			}
			q=q->next;
		}
		p=p->next;
		q=first2;
	}
	r=first3;

	int maxzhi;
	for(i=0;i<f3;i++){
		maxzhi=-1;
		r=first3;
		for(j=0;j<f3;j++){
			if(r->zhi>maxzhi){
				maxzhi=r->zhi;
			}
			r=r->next;
		}
		r=first3;
		while(r->zhi!=maxzhi)r=r->next;
		printf("%d %d ",r->xi,r->zhi);
		r->zhi=-1;
	}
	return 0;
}

