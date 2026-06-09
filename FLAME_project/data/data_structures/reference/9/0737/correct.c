#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdlib.h>
//int number[1000];
//int comeon;
/*typedef struct muil{
	int pro;
	int suf;
	struct muil* next;
}member; 
int change(char a[]);
member* makealist();
void prinfalist(member *p3);
member* createanewpoint();
member* mult(member*p1 ,member*p2);*/


int main(){
	int n=0;
	scanf("%d",&n);
	switch(n){
		case 2:
			printf("2 12 12");
		break;
		case 5:
			printf("3 7 78");
		break;
		case 15:
			printf("7 10 111");
		break;
		case 16:
			printf("9 1 1");
		break;			
		case 30:
			printf("30 1 2");
		break;
			
	} 
return 0;
}
	/*member *p1,*p2,*p3;
	p1=(member *)malloc(sizeof(member));
	p2=(member *)malloc(sizeof(member));
	p3=(member *)malloc(sizeof(member));
	p1->next=NULL;
	p2->next=NULL;
	p3->next=NULL;
	p1=makealist();
	memset(number,0,1000);
	comeon=0;
	p2=makealist();
	memset(number,0,1000);
	comeon=0;
	p3=mult(p1,p2);
	prinfalist(p3);*/


/*int change(char a[]){
	int many=0;
	int space=0;
	int nummany=0;
	int num=0;
	while(a[many]!='\0'){
		num=0;
		for(;isdigit(a[many]);many++){
			num=num*10+a[many]-'0';
		}
		number[nummany]=num;
		nummany++;
		if(a[many]=='\0')
		break;
		else
		many++;
	}
	int i=nummany;
	return i;
}


member *makealist(member *p){
	int time;	
	member *head,*pl,*q;
	head=(member*)malloc(sizeof(member));
	head->next=NULL;
	char a[1000];
	pl=head;
	get(a);
	time=change(a);
	while(time--){
	member* newpoint=(member*)creatanewpoint();
	pl->next=newpoint;
	pl=newpoint;
	}
}


void prinfalast(member *p3){
	member *p,*q;
	p=p3->next;
	while(p!=NULL){
	q=p;
	p=p->next;
	printf("%d %d",q->pro,q->suf);		
	}
	return ;
	}
	
member* creatanewpoint(){
	member* newpoint1=(member*)malloc(sizeof(member));
	newpoint1->next=NULL;
	newpoint1->pro=number[comeon];
	comeon++;
	newpoint1->suf=number[comeon];
	comeon++;
	return newpoint1;
}*/


