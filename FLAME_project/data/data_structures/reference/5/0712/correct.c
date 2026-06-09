#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
char s1[10000],s2[10000];
struct item{
	int coe;//系数 
	int pow;//指数
	struct item *next; 
}*p,*q,*res,*start1,*start2,*start_res,*t; 

void fuck(){
	
}
void getNum(){
	int len1=strlen(s1);
	int len2=strlen(s2);
	struct item *start1=p;struct item *start2=q;
	int tem=0,i=0;
	while(i<len1){
		while(s1[i]!=' '){
			tem*=10;	tem+=s1[i]-'0';		i++;
		}//得到一个数 
		p->coe=tem;		tem=0;		i++; 
		
		while(s1[i]!=' '&&i<len1){
			tem*=10;	tem+=s1[i]-'0';		i++;
		}
		p->pow=tem;		tem=0;		i++;
		
		if(i-1==len1){//特判，有没有到最后一位 
			p->next=NULL;break;
		}
		p->next=malloc(sizeof(struct item));
		p=p->next;
	}
	p=start1;
	
	i=0;
	while(i<len2){
		while(s2[i]!=' '){
			tem*=10;	tem+=s2[i]-'0';		i++;
		}
		q->coe =tem;	tem=0;		i++;
		while(s2[i]!=' '&&i<len2){
			tem*=10;	tem+=s2[i]-'0';		i++;
		}
		q->pow=tem;		tem=0;		i++;
		if(i-1==len2){
			q->next=NULL;break;
		}
		q->next=malloc(sizeof(struct item));
		q=q->next;
	}
	q=start2;
//	while(q!=NULL){
//		printf("%d %d ",q->coe,q->pow);
//		q=q->next;
//	} 
} 
int main(){
	p=malloc(sizeof(struct item));start1=p;
	q=malloc(sizeof(struct item));start2=q;
	res=malloc(sizeof(struct item));res->next=NULL;start_res=res;
	gets(s1);gets(s2);
	getNum(start1,start2);
	p=start1;
	q=start2;
	res->pow=p->pow+q->pow;
	res->coe=p->coe*q->coe;
	res->next=NULL; 
	int tt=-1;//特判第一次 
//	printf("here!\n");return 0;
	while(p!=NULL){
//		printf("p->coe is %d ,p->pow is %d \n",p->coe,p->pow);
		if(tt==0){
			q=start2;
		}
		else{
			q=start2->next;
			tt=0;
		}
		while(q!=NULL){
//			printf("q->coe is %d, q->pow is %d\n",q->coe,q->pow);
			res=start_res;
			int t_coe=p->coe*q->coe;
			int t_pow=p->pow+q->pow;//得到指数和幂的乘积 
			int flag=0;//flag=1表示这个新的乘积被放进了res里面 
			while(res!=NULL){//遍历之前的res 
				if(res->pow == t_pow){//if find, the coe of the item plus t_coe;
					res->coe+=t_coe;
					flag=1;break;
				} 
				else if (res->pow>t_pow && res->next==NULL)break;
				else if (res->pow>t_pow && (res->next)->pow>=t_pow) res=res->next;//if not found,move on
				else if (res->pow>t_pow && (res->next)->pow<t_pow){//create a new item between;
					t=malloc(sizeof(struct item));
					t->coe =t_coe;t->pow=t_pow;t->next=res->next;res->next =t;
					flag=1;break;
				}
			}
			if(flag==0){//which means the existing pows are all bigger than t_pow 
				res->next=malloc(sizeof(struct item));
				res=res->next;res->coe=t_coe;res->pow=t_pow;res->next=NULL;//新建立了一个节点 
			}	
			q=q->next;
		}
//		printf("here\n");
		p=p->next;
	}
	res=start_res;
	while(res!=NULL){
		printf("%d %d ",res->coe,res->pow);
		res=res->next;
	}
	return 0;
}


