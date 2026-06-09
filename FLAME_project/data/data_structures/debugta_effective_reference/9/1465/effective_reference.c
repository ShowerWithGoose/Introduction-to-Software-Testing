#include<stdio.h>
#include<stdlib.h>
struct seg{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
	struct seg *link; 
}; 
int cmp(const void *p1,const void *p2){
	struct seg *f1=(struct seg*)p1;
	struct seg *f2=(struct seg*)p2;
	return f1->x1-f2->x1; 
}
int main()
{
	struct seg A[105],*X=NULL,*p=NULL,*head=NULL;
	int n,i,j,t=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&A[i].x1,&A[i].y1,&A[i].x2,&A[i].y2);
		A[i].len=1;
		A[i].link=NULL;
	} 
	qsort(A,n,sizeof(struct seg),cmp);
	for(i=0;i<n-1;i++){
		if(A[i].len!=1)
			continue;
		head=&A[i];
		p=&A[i];
		for(j=i+1;j<n;j++){
			if(A[j].len!=1)
				continue;
			if(((p->x2)==(A[j].x1))&&((p->y2)==(A[j].y1))){
				A[j].len=(p->len)+1;
				p->link=&A[j];
				p=&A[j];
			}
		}
		if(p->len>t){
			t=p->len;
			X=head;
		}
	}
	printf("%d %d %d",t,X->x1,X->y1);
	return 0;
} 

