#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct node{
	int coe;
	int pow;
	struct node *link;
}Lnode,*linklist;

int main(){
	linklist q1,p1,r1,list1=NULL,q2,p2,r2,p0=NULL,list2=NULL;
	int a,n;
	char c;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q1=(linklist)malloc(sizeof(Lnode));
		q1->coe=a;
		q1->pow=n;
		q1->link=NULL;
		if(list1==NULL){
			list1=p1=q1;
		}else{
			p1->link=q1;
			p1=q1;
		}
	}while(c!='\n');
	int a2,n2;
	do{
		scanf("%d%d%c",&a,&n,&c);
		for(p1=list1;p1!=NULL;p1=p1->link){
			a2=a*p1->coe;
			n2=n+p1->pow;
			q2=(linklist)malloc(sizeof(Lnode));
			q2->coe=a2;
			q2->pow=n2;
			q2->link=NULL;
			if(list2==NULL){
				list2=p2=q2;
			}
			else{
				for(p2=list2;p2!=NULL;p0=p2,p2=p2->link){
					if(q2->pow>p2->pow){
						if(p2==list2){
							q2->link=list2;
							list2=q2;
							break;
						}else{
							q2->link=p0->link;
							p0->link=q2;
							break;
						}
					}
					else if(q2->pow==p2->pow){
						p2->coe=p2->coe+q2->coe;
						break;
					}
				}
				if(p2==NULL){
					p0->link=q2;
				}
			}
		} 		 
	}while(c!='\n');
	for(p2=list2;p2!=NULL;p2=p2->link){
		printf("%d %d ",p2->coe,p2->pow);
	}
}
	
























