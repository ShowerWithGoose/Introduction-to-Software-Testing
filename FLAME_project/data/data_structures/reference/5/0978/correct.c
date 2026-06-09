#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count;
struct node{
	int a;//a系数 
	int n;//n指数 
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr read() ;//读入函数 
Nodeptr multi(Nodeptr list1,Nodeptr list2);//多项式乘法  

int main (){
	Nodeptr p,list1=NULL,list2=NULL,listOutcome=NULL;
	list1=read();
	list2=read();
	listOutcome=multi(list1,list2);
	for(p=listOutcome;p->link!=NULL;p=p->link){
		printf("%d %d ",p->a,p->n);
	}
	printf("%d %d ",p->a,p->n);
	return 0;
}
Nodeptr read(){
	Nodeptr p,q,list=NULL;//p移动，q临时新，list头
	while(1){
		q=(Nodeptr)malloc(sizeof(Node));
		scanf("%d %d",&q->a,&q->n);
		q->link=NULL;
		if(list==NULL)list=p=q;
		else{
			p->link=q;//将新节点接到链尾 
			p=q;//移动p（移动节点） 
		}
		if('\n'==getchar())break;//!!!读到换行符结束循环！！！！！ 
	} 
	return list;	
}
Nodeptr multi(Nodeptr list1,Nodeptr list2){
	Nodeptr list=NULL,p,q,p1,p2;
	int length1,length2,i,j,flag;
	for(length1=1,p1=list1;p1->link!=NULL;p1=p1->link,length1++);//list1的长度 
	for(length2=1,p2=list2;p2->link!=NULL;p2=p2->link,length2++);//list2的长度 
	for(i=0,count=0,p1=list1;i<length1;p1=p1->link,i++){//list1每一项与list2每一项相乘得到list 
		for(j=0,p2=list2;j<length2;p2=p2->link,j++){
			q=(Nodeptr)malloc(sizeof(Node));//q临时结点，p移动节点； 
			q->a= p1->a * p2->a;
			q->n= p1->n + p2->n;
			q->link=NULL;
			count++;
			if(list==NULL)list=p=q;
			else {
				p->link=q;
				p=q;
			}
		}
	}
	//冒泡排序！！！从大到小降序 
	Nodeptr px;//r临时节点，px和p为移动节点 
	int a1,n1;
	px=(Nodeptr)malloc(sizeof(Node));
	for(i = 0; i < count-1; i++) {
		flag = 0;
		for( j = 1,px=list->link; j < count-1 && px->link!=NULL; j++,px=px->link)
			if(px->n < px->link->n) {
				a1 =px->a;
				n1 =px->n;
				px->a = px->link->a;
				px->n = px->link->n;
				px->link->a =a1;
				px->link->n =n1; //px->next p-a-b- p-b-a
				flag = 1;
			}
		if (flag == 0)
			break;
	}
	for(i=0,p=list;p->link!=NULL;i++){
		if(p->n==p->link->n){
			p->a += p->link->a;
			q=p->link;
			p->link=q->link;
			free(q);
		}
		if(p->n!=p->link->n)p=p->link ;
	}
	return list;
}

