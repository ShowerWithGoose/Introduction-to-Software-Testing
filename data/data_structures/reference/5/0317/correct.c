#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct group{
	int corfficient;
	int index;
	struct group *link;
};
int main()
{
	int cfsint,indx,flag=0;
	struct group *p1,*q1,*p2,*q2,*list1=NULL,*list2=NULL;
	struct group *p3,*q3,*r3,*list3=NULL;
	char c;
	
	while(1){
		scanf("%d %d%c",&cfsint,&indx,&c);
		
		q1=(struct group*)malloc(sizeof(struct group));
		q1->link=NULL;
		q1->index=indx;
		q1->corfficient=cfsint;
		if(list1==NULL)
			p1=list1=q1;
		else{
			p1->link=q1;
			p1=q1;
		}
		if(c=='\n')
			break;
	}
	
	while(1){
		scanf("%d %d%c",&cfsint,&indx,&c);
		
		q2=(struct group*)malloc(sizeof(struct group));
		q2->link=NULL;
		q2->index=indx;
		q2->corfficient=cfsint;
		if(list2==NULL)
			p2=list2=q2;
		else{
			p2->link=q2;
			p2=q2;
		}
		if(c=='\n')
			break;
	}
	
	for(p1=list1;p1!=NULL;p1=p1->link){
		for(p2=list2;p2!=NULL;p2=p2->link){
			if(list3==NULL){
				r3=(struct group*)malloc(sizeof(struct group));
				list3=p3=r3;
				r3->index=p2->index+p1->index;
				r3->corfficient=p1->corfficient*p2->corfficient;
				r3->link=NULL;
			}
			else{
				flag=0;
				for(p3=list3;p3!=NULL;p3=p3->link)
					if(p3->index==p2->index+p1->index){
						p3->corfficient+=p1->corfficient*p2->corfficient;
						flag=1;
					}
				if(flag==0){
					for(p3=list3;p3!=NULL && p3->index>p2->index+p1->index;q3=p3,p3=p3->link);
					r3=(struct group*)malloc(sizeof(struct group));
					r3->link=p3;
					q3->link=r3;
					r3->index=p2->index+p1->index;
					r3->corfficient=p1->corfficient*p2->corfficient;
				}
			}
		}
	}
	
	for(p3=list3;p3!=NULL;p3=list3){
		printf("%d %d ",p3->corfficient,p3->index);
		list3=p3->link;
		free(p3);
	}

	return 0;
}


