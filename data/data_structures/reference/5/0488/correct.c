#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int a;
	int x;
	struct node *link;
}LNode,*LinkList;

typedef struct save{
	long long a;
	long long x;
}LSave,*SaveList;

LinkList CREAT();
int cmp(const void *a,const void *b);

LinkList list_a,list_b;
SaveList list_c;
int lena=0,lenb=0,length;

int main(){
	LinkList p,q;
	SaveList r;
	int i,j,k=1;
	long long a,x;
	list_a=CREAT();
	lena=length;
	list_b=CREAT();
	lenb=length;
	
	list_c=(SaveList)malloc(sizeof(LSave)*lena*lenb);//存放乘积
	p=list_a,r=list_c;
	for(i=1;i<=lena;i++){
		q=list_b;
		for(j=1;j<=lenb;j++){
			r->a=p->a*q->a;
			r->x=p->x+q->x;
			r++;
			q=q->link;
		}
		p=p->link;
	}
	qsort(list_c,lena*lenb,sizeof(LSave),cmp);//乘积按指数排序
	r=list_c;
	for(i=1;i<=lena*lenb;i++){
		a=x=0;
		if(r->x==(r+1)->x){
			while(r->x==(r+1)->x){
				a+=r->a;
				r++;
				i++;
			}
			a+=r->a;
			x=r->x;
		}else{
			a=r->a;
			x=r->x;
		}
		printf("%lld %lld ",a,x);
		r++;
	}
	
	return 0;
}

int cmp(const void *a,const void *b){
	SaveList aa=(SaveList)a;
	SaveList bb=(SaveList)b;
	return bb->x>aa->x?1:-1;
}

LinkList CREAT(){
	char s[1000];
	int i=0,num;
	length=0;
	LinkList p,r,list=NULL;
	gets(s);
	while(s[i]!='\0'){
		p=(LinkList)malloc(sizeof(LNode));
		p->link=NULL;//指针域设置
		if(s[i]==' ')
			i++;
		num=0;
		while(s[i]>='0'&&s[i]<='9'){
			num*=10;
			num+=s[i]-'0';
			i++;
		}//读系数
		p->a=num;
		i++;
		num=0;
		while(s[i]>='0'&&s[i]<='9'){
			num*=10;
			num+=s[i]-'0';
			i++;
		}//读指数
		p->x=num;
		length++;
		if(list==NULL)
			list=p;
		else
			r->link=p;
		r=p;
	}
	return list;
}

