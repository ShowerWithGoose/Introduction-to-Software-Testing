#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int z;
	int x;
	struct node*lik;
};

typedef struct node* Nodeptr;
typedef struct node Node;

int main()
{
	Nodeptr g,e,f,list,p,p2,q,q2,head,head2;head=head2=list=NULL;
	char a[200]={'\0'};
	int c,b,i,j;j=i=c=b=0;
	for(i=0;i<2;i++){
		memset(a,'\0',200);
		gets(a);
		j=0;
		while(a[j]!='\0'){
			while(a[j]!=' '&&a[j]!='\0'){
				c*=10;
				c+=a[j]-'0';
				j++;
			}
			j++;
			while(a[j]!=' '&&a[j]!='\0'){
				b*=10;
				b+=a[j]-'0';
				j++;
			}
			j++;
			if(i==0){
				p=(Nodeptr)malloc(sizeof(Node));
				p->x=c;
				p->z=b;
				p->lik=NULL;
				if(head==NULL){
					head=q=p;
				} 
				else{
					q->lik=p;
					q=p;
				}
				b=c=0;	
			}
			else{
				p2=(Nodeptr)malloc(sizeof(Node));
				p2->x=c;
				p2->z=b;
				p2->lik=NULL;
				if(head2==NULL){
					head2=q2=p2;
				} 
				else{
					q2->lik=p2;
					q2=p2;
				}
				b=c=0;
			}
		}
	}
	for(q=head;q!=NULL;q=q->lik){
		for(q2=head2;q2!=NULL;q2=q2->lik){
			e=(Nodeptr)malloc(sizeof(Node));
			e->x=q->x*q2->x;
			e->z=q->z+q2->z;
			e->lik=NULL;
			if(list==NULL){
				list=g=f=e;
			}
			else{
				g=f;
				for(f=list;f!=NULL;f=f->lik){
					if(f->z==e->z){
						f->x+=e->x;
						free(e);
						break;
					}
					else if(f->lik==NULL&&f->z>e->z){
						f->lik=e;
						f=e;
						break;
					}
					else if(f->z>e->z&&(f->lik)->z<e->z){
						e->lik=f->lik;
						f->lik=e;
						break;
					}
				}
			}
		}
	}
	for(f=list;f!=NULL;f=f->lik){
		printf("%d %d ",f->x,f->z);
	}
	for(p=head;p!=NULL;p=p->lik){
		free(p);
	}
	for(p2=head2;p2!=NULL;p2=p2->lik){
		free(p2);
	}
	for(f=list;f!=NULL;f=f->lik){
		free(f);
	}
 	return 0;
}

