//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6
char s[1005];
typedef struct Node{
	int xishu;
	int zhishu;
	struct Node* next;
}xiang;
int n1=0,n2=0;
xiang* creatlink(){
	xiang* p=(xiang*)malloc(sizeof(xiang));
	p->xishu=-1; p->zhishu=-1;
	xiang* temp=p;
	int x,z;
	char ch;
	while(scanf(" %d %d%c",&x,&z,&ch)){
		xiang* a=(xiang*)malloc(sizeof(xiang));
		a->xishu=x; a->zhishu=z;
		temp->next=a;
		temp=temp->next;
		if(ch=='\n') break;
	}
	temp->next=NULL; 
	return p;
}
xiang* charu(xiang* a,xiang* p){
	xiang* temp=p;
	while(1){
		if(temp==NULL) break;
		
		if(a->zhishu==temp->zhishu){
			temp->xishu+=a->xishu;
			return p;
		} 
		else if((temp->next==NULL)||(temp->next->zhishu < a->zhishu)){
			a->next=temp->next;
			temp->next=a;
			return p;
		}else {
			temp=temp->next;
		}
	}
	return p;
}
xiang* cheng(xiang* s1,xiang* s2){
	xiang* p=(xiang*)malloc(sizeof(xiang));
	p->xishu=-1; p->zhishu=-1;
	xiang* temp=p;
	temp->next=NULL;
	xiang* p1=s1->next;
	xiang* p2=s2->next;
/*	while(p2!=NULL){
		xiang* a=(xiang*)malloc(sizeof(xiang));
		a->xishu=p1->xishu * p2->xishu;
		a->zhishu=p1->zhishu + p2->zhishu;
		p=charu(a,p);
		p2=p2->next;
	}
	p1=p1->next;*/
	while(p1!=NULL){
		p2=s2->next;
		while(p2!=NULL){
			xiang* a=(xiang*)malloc(sizeof(xiang));
			a->xishu=p1->xishu * p2->xishu;
			a->zhishu=p1->zhishu + p2->zhishu;
			p=charu(a,p);
			p2=p2->next;
		}
		p1=p1->next;
	}
	return p;
}
xiang *s1,*s2;
int main(){
	s1=creatlink(); 
	s2=creatlink();
	xiang* s3=(xiang*)malloc(sizeof(xiang));
	s3=cheng(s1,s2);
	xiang* del=s3;
	s3=s3->next;
	free(del);
	while(1){
		if(s3!=NULL){
			del=s3;
			printf("%d %d ",s3->xishu,s3->zhishu);
			s3=s3->next;
			free(del); 
		}else {
			free(s3); break;
		}
	}
	while(1){
		if(s2->next!=NULL){
			del=s2; s2=s2->next;
			free(del); 
		}else {
			free(s2);break;
		}
	}
	while(1){
		if(s1->next!=NULL){
			del=s1; s1=s1->next;
			free(del); 
		}else{
			free(s1);break;
		} 
	}
	
	return 0;
}


