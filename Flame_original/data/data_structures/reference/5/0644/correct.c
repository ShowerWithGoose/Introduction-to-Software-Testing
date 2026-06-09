#include <stdio.h>
#include <stdlib.h>
struct let{
	long long int a;
	long long int b;
	struct let *next;
};
typedef struct let sup;
typedef struct let *supr;
sup ans[1000];
supr list1,list2,list3,p1,p2,p3;
char c1,c2;
int main(){
	list1=p1=(supr)malloc(sizeof(sup));
	list2=p2=(supr)malloc(sizeof(sup));
	list1->next=(supr)malloc(sizeof(sup));
	list2->next=(supr)malloc(sizeof(sup));
	
	list3=p3=(supr)malloc(sizeof(sup));
	list3->next=(supr)malloc(sizeof(sup));
	while(1){
		supr q1;
		q1=(supr)malloc(sizeof(sup));
		scanf("%lld%lld%c",&q1->a,&q1->b,&c1);
		p1->next=q1;
		p1=p1->next;
		if(c1=='\n')
		break;
	}
	p1->next=NULL;
	while(1){
		supr q2;
		q2=(supr)malloc(sizeof(sup));
		scanf("%lld%lld%c",&q2->a,&q2->b,&c2);
		p2->next=q2;
		p2=p2->next;
		if(c2=='\n')
		break;
	}
	p2->next=NULL;
	supr vis1,vis2;
	vis1=list1->next;vis2=list2->next;
	
	while(vis1!=NULL){
		while(vis2!=NULL){
			supr q3;
			q3=(supr)malloc(sizeof(sup));
			q3->a=vis1->a*vis2->a;
			q3->b=vis1->b+vis2->b;
			p3->next=q3;
			p3=p3->next;
			vis2=vis2->next;
		}
		vis2=list2->next;
		vis1=vis1->next;
	}
		
	
	p3->next=NULL;
	supr vis3;
	/*vis3=list1->next;
	while(vis3!=NULL){
		printf("%lld %lld ",vis3->a,vis3->b);
		vis3=vis3->next;
	}
	printf("\n");
	vis3=list2->next;
	while(vis3!=NULL){
		printf("%lld %lld ",vis3->a,vis3->b);
		vis3=vis3->next;
	}
	printf("\n");*/
	/*vis3=list3->next;
	while(vis3!=NULL){
		printf("%lld %lld ",vis3->a,vis3->b);
		vis3=vis3->next;
	}*/
	vis3=list3->next;
	sup temp;
	int i=0,j=0,k=0,l;
	while(vis3!=NULL){
		ans[i++]=*vis3;
		vis3=vis3->next;
	}
	for(j=0;j<i;j++){
		for(k=j+1;k<i;k++){
			if(ans[k].b>ans[j].b){
				temp=ans[k];
				ans[k]=ans[j];
				ans[j]=temp;
			}else if(ans[k].b==ans[j].b){
				ans[j].a+=ans[k].a;
				for(l=k;l<i-1;l++){
					ans[l]=ans[l+1];
				}
				i--;
			}
		}
	}
	for(j=0;j<i;j++){
		printf("%d %d ",ans[j].a,ans[j].b);
	}
	return 0;
}

