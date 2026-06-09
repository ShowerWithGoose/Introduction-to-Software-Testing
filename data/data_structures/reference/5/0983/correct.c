#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct poly {
	long long coe;
	long long ind;
	struct poly *next;
};
int main()
{
	
	struct poly *first1,*pre1,*first2,*pre2,*first3,*pre3,*pre3_b,*tmp;
	char c1,c2;
	first1=(struct poly *)malloc(sizeof(struct poly));
	pre1=first1;
	scanf("%lld%c%lld%c",&first1->coe,&c1,&first1->ind,&c2);
	first1->next=NULL;
	while(c2!='\n'){
		pre1->next=(struct poly *)malloc(sizeof(struct poly));
		pre1=pre1->next;
		scanf("%lld%c%lld%c",&pre1->coe,&c1,&pre1->ind,&c2);
	}
	pre1->next=NULL;
	first2=(struct poly *)malloc(sizeof(struct poly));
	pre2=first2;
	scanf("%lld%c%lld%c",&first2->coe,&c1,&first2->ind,&c2);
	first2->next=NULL;
	while(c2!='\n'){
	pre2->next=(struct poly *)malloc(sizeof(struct poly));
	pre2=pre2->next;
	scanf("%lld%c%lld%c",&pre2->coe,&c1,&pre2->ind,&c2);
	}
	pre2->next=NULL;
	first3=(struct poly *)malloc(sizeof(struct poly));
	first3->coe=first1->coe*first2->coe;
	first3->ind=first1->ind+first2->ind;
	first3->next=(struct poly *)malloc(sizeof(struct poly));
	pre3=first3->next;
	pre3->next=NULL;
	pre3->coe=0,pre3->ind=0;
	pre3_b=first3;
	pre1=first1;
	pre2=first2->next;
	
	while(pre1!=NULL){
		while(pre2!=NULL){
			tmp=(struct poly *)malloc(sizeof(struct poly));
			tmp->next=NULL;
			tmp->coe=pre1->coe*pre2->coe;
			tmp->ind=pre1->ind+pre2->ind;
			while(pre3!=NULL){
				if(tmp->ind<pre3->ind){
					if(pre3->next!=NULL){
						pre3_b=pre3;
						pre3=pre3->next;
					}
					else{
						pre3->next=(struct poly *)malloc(sizeof(struct poly));
						pre3_b=pre3;
						pre3=pre3->next;
						pre3->coe=tmp->coe;
						pre3->ind=tmp->ind;
						pre3->next=NULL;
						break;
					}
				}
				else if(tmp->ind>pre3->ind){
					if(pre3->coe==0&&pre3->ind==0){
						pre3->coe=tmp->coe;
						pre3->ind=tmp->ind;
						break;
					}
					else{
						tmp->next=pre3;
						pre3_b->next=tmp;
						pre3_b=pre3_b->next;
						break;
					}
				}
				else{
					pre3->coe+=tmp->coe;
					break;
				}	
			}
			pre3_b=first3,pre3=first3->next;
			pre2=pre2->next;
		}
		pre2=first2;
		pre1=pre1->next;
	}
	pre3=first3;
	while(pre3!=NULL&&(pre3->coe!=0||pre3->ind!=0)){
		printf("%lld %lld ",pre3->coe,pre3->ind);
		pre3=pre3->next;
	}
	pre1=first1,pre2=first2,pre3=first3;
	while(pre1!=NULL){
		tmp=pre1;
		pre1=pre1->next;
		free(tmp);
	}
	while(pre2!=NULL){
		tmp=pre2;
		pre2=pre2->next;
		free(tmp);
	}
	while(pre3!=NULL){
		tmp=pre3;
		pre3=pre3->next;
		free(tmp);
	}
	return 0;
}

