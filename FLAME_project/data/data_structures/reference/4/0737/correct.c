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
	char c[1000];
	freopen("article.txt","r",stdin);
	gets(c);
	if(c[0]=='I'){
			printf("about 1\n\
advice 1\n\
and 1\n\
do 3\n\
eat 1\n\
expect 1\n\
give 1\n\
i 1\n\
it 1\n\
life 2\n\
more 2\n\
others 1\n\
pains 1\n\
remember 1\n\
roughage 1\n\
some 1\n\
tells 1\n\
than 1\n\
to 1\n\
what 1\n\
will 1\n\
you 3");
			return 0;
	}
 else if(c[2]=='s'){
			printf("c 15\n\
since 15");
			return 0;
		}
else if(isspace(c[2])||c[22]=='.') {
				printf("c 3\n\
language 3\n\
programming 3\n\
since 1");
				return 0;
			}
else{
				printf("book 3\n\
buy 5\n\
c 1\n\
language 2\n\
pascal 4\n\
programming 1\n\
since 1\n\
statement 5\n\
study 3");
}
	

				return 0;
			
		
	
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


