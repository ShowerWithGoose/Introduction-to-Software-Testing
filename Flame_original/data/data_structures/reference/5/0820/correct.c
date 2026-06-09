#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct muti{
	long long factor;
	long long index;
	struct muti *next;
}arry[3]={0,0,NULL};
int main (){
	char s;
	struct muti *p,*q,*ptr;
	p=(struct muti*)malloc(sizeof(struct muti));
	p->next=NULL;
	q=&arry[0];
	while(1){
		scanf("%lld%lld",&q->factor,&q->index);
		s=getchar();
		if(s=='\n'){
			break;
		}
		else {
			q->next=p;
			q=q->next;
			p=(struct muti*)malloc(sizeof(struct muti));
			p->next=NULL;
		}
	}
	p=(struct muti*)malloc(sizeof(struct muti));
	p->next=NULL;
	q=&arry[1];
	while(1){
		scanf("%lld%lld",&q->factor,&q->index);
		s=getchar();
		if(s=='\n'){
			break;
		}
		else {
			q->next=p;
			q=q->next;
			p=(struct muti*)malloc(sizeof(struct muti));
			p->next=NULL;
		}
	}
	p=&arry[0];
	q=&arry[1];
	ptr=&arry[2];
	while(1){
		while(1){
			ptr->factor=p->factor*q->factor;
			ptr->index=p->index+q->index;
			ptr->next=NULL;
					
			
			if(q->next==NULL){
				q=&arry[1];
				break;
			}
			ptr->next=(struct muti*)malloc(sizeof(struct muti));
			ptr=ptr->next;	
			q=q->next;
		}
		if(p->next==NULL){
			break;
		}
		ptr->next=(struct muti*)malloc(sizeof(struct muti));
		ptr=ptr->next;
		ptr->next=NULL;	
		p=p->next;
	}//至此，相乘与读取结束，下一步按幂次排序，合并同幂次，输出 
	int ob=1;
	struct muti* first;
	ptr=&arry[2];
	first=&arry[2];
	struct muti* temp,*front;
	while(ob==1){
		ob=0;
		while(ptr->next!=NULL){
			if(ptr->index<ptr->next->index){
				if(ptr==first){
					first=ptr->next;
				}
				temp=ptr->next;
				ptr->next=ptr->next->next;
				temp->next=ptr;
				ptr=temp;
				front->next=temp;
				ob=1;
			}
			else if(ptr->index==ptr->next->index){
				ob=1;
				ptr->factor+=ptr->next->factor;
				ptr->next=ptr->next->next;
			}
			front=ptr;
			ptr=ptr->next;
		}
		ptr=first;
	}
	ptr=first;
	while(ptr->next!=NULL){
		if(ptr->factor!=0){
			printf("%lld %lld ",ptr->factor,ptr->index);
		}
		ptr=ptr->next;
	}
	printf("%lld ",ptr->factor);

	printf("%lld ",ptr->index);
	
	return 0;
}
 

