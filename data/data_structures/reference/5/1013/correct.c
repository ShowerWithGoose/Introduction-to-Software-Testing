#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe;
	int pow;
	struct Node *next;
};
int main(){
	struct Node *p1, *p2, *q, *head1, *head2, *p0, *m;
	struct Node f[200], h[200], r;
	int i=0, j, x=0, y, z;
	char c;
	head1=p1=NULL;
	head2=p2=NULL;
	do{
		scanf("%d%d%c",&h[x].coe,&h[x].pow,&c);
		x++;
		}while(c!='\n');
		y=x;
	for(x=0;x<y-1;x++){
		for(z=0;z<y-x-1;z++){
			if(h[z].pow<h[z+1].pow){
				r=h[z];
				h[z]=h[z+1];
				h[z+1]=r;
			}
		}
	}
	for(x=0;x<y;x++){
		if(head1==NULL){
			head1=p1=(struct Node*)malloc(sizeof(struct Node));
		}
		else{
			p1->next=(struct Node*)malloc(sizeof(struct Node));
			p1=p1->next;
		}
		p1->coe=h[x].coe;p1->pow=h[x].pow;p1->next=NULL;}
	for(p1=head1;p1!=NULL;p1=p1->next){
		if(head2==NULL){
			head2=p2=(struct Node*)malloc(sizeof(struct Node));
		}
		else{
			p2->next=(struct Node*)malloc(sizeof(struct Node));
			p2=p2->next;
		}
		p2->coe=p1->coe;p2->pow=p1->pow;p2->next=NULL;
	}
	do{
		scanf("%d%d%c",&f[i].coe,&f[i].pow,&c);
		i++;
	}while(c!='\n');
	q=(struct Node*)malloc(sizeof(struct Node));
	q->coe=f[0].coe;q->pow=f[0].pow;q->next=NULL;
	for(p2=head2;p2!=NULL;p2=p2->next){
		p2->coe=p2->coe*q->coe;p2->pow=p2->pow+q->pow;
	}
	j=i;
	for(i=1;i<j;i++){
		q=(struct Node*)malloc(sizeof(struct Node));
		q->coe=f[i].coe;q->pow=f[i].pow;q->next=NULL;
		for(p1=head1;p1!=NULL;p1=p1->next){
		m=(struct Node*)malloc(sizeof(struct Node));
		m->coe=q->coe*p1->coe;m->pow=q->pow+p1->pow;m->next=NULL;
			for(p2=head2;p2!=NULL;p0=p2,p2=p2->next){
				
				if(m->pow==p2->pow){
					p2->coe=m->coe+p2->coe;
					break;
				}
				else if(m->pow>p2->pow){
					if(p2==head2){
						m->next=head2;
						head2=m;
						break;
					}
					else {
						m->next=p2;
						p0->next=m;
						break;
					}
				}
				
				}
				if(p2==NULL) p0->next=m;
			}
	}while(c!='\n');
	for(p2=head2;p2!=NULL;p2=p2->next){
		printf("%d %d ",p2->coe,p2->pow);
	}
	return 0;
}

