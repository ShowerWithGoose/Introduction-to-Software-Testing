#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct a{
	int coe,exp;
	struct a* next;
};

int main(){
	int i,j,k;
	int n1=0,n2=0;
	int a[100][2]={{}},b[100][2]={{}}; 
	char c=' ';
	struct a* head=(struct a*)malloc(sizeof(struct a));
	head->next=NULL;
	head->exp=-1;
	struct a* p=head;
	for(i=0;c!='\n';i++)
		scanf("%d%d%c",&a[i][0],&a[i][1],&c);
	c=' ';
	for(j=0;c!='\n';j++)
		scanf("%d%d%c",&b[j][0],&b[j][1],&c);
	n1=i,n2=j;
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			struct a* s=(struct a*)malloc(sizeof(struct a));
			s->coe=a[i][0]*b[j][0];
			s->exp=a[i][1]+b[j][1];
		
		p=head;
		while(1){
			if(s->exp==p->exp){
				p->coe+=s->coe;
				break;
			}
			else if(p->next==NULL){
				p->next=s;
				s->next=NULL;
				break;
			}
			else if(s->exp>p->next->exp){
				s->next=p->next;
				p->next=s;
				break;
			}				
			p=p->next;	
		}
		
	}
	
	}
	p=head->next;
	while(p!=NULL){
		printf("%d %d ",p->coe,p->exp);
		p=p->next;
	}
}

