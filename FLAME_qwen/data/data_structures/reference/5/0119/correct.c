#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mulit{
	int coe;//ÏµÊý¡£ 
	int pow;//ÃÝ¡£
	struct mulit *next; 
};
int search_list(struct mulit*list,struct mulit*item);
int insert_list(struct mulit*list,struct mulit*item);

int main(){
	struct mulit *list=NULL;
	struct mulit *p,*q;
	int n,k,i=0,j=0,a[105],b[105],a2[105],b2[105],a0,b0,a1,b1;
	char c;
	do{
		scanf("%d%d%c",&a0,&b0,&c);
		a[i]=a0;
		b[i]=b0;
		i++;
	}while(c!='\n');
	n=i;
	do{
		scanf("%d%d%c",&a0,&b0,&c);
		for(i=0;i<n;i++){
			p=(struct mulit*)malloc(sizeof(struct mulit));
			p->coe=a[i]*a0;
			p->pow=b[i]+b0;
			p->next=NULL;
			if(list==NULL){
				list=p;
			}
			else {
				if(search_list(list,p)==-1){
				fprintf(stderr,"Memory is full!\n");
			    return -1;
	            }
			}
	    }
	}while(c!='\n');


	for(p=list;p!=NULL;p=p->next){
		printf("%d %d ",p->coe,p->pow);
	}
	return 0;
}
int search_list(struct mulit *list,struct mulit *item){
	struct mulit *p,*q=NULL;
	for(p=list;p!=NULL;p=p->next){
		if(p->pow==item->pow){
			p->coe=p->coe+item->coe;
			return 0;
		}
		//else break;
	}
	return insert_list(list,item);
	
}
int insert_list(struct mulit*list,struct mulit*item){
	struct mulit *q,*p;
	if(list==NULL){
		list=item;
	}
	else if(item->pow>list->pow){
		item->next=list;
		list=item;
	}
	else{
		for(q=list;q!=NULL&&item->pow<q->pow;p=q,q=q->next)
		;
		p->next=item;
		item->next=q;
	}
	return 0;
}


