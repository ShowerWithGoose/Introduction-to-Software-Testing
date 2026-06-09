#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
char s[100005];
int a[100005];
int b[100005];
typedef struct fun{
	int a;
	int b;
	struct fun *link;
}POL;
POL *m[1005],*temp;
int change(char s[],int *c){//转化数据类型 
	int j=1;
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]==' ')
			j++;
		else 
			c[j]=c[j]*10+s[i]-'0';
	}
	return j/2;
}
POL* create(int c[],int n){//创建一个新的单向链表 
	POL *p,*r,*list=NULL;
	for(int i=1; i<=2*n; i+=2){
		p=(POL*)malloc(sizeof(POL));
		p->a=c[i];
		p->b=c[i+1]; 
		p->link=NULL;
		if(list==NULL)list=p;
		else r->link=p;
		r=p;		
	}r->link=NULL;
	return list; 
}
POL* multi(POL *p,POL *q){//做乘法，输出链表头 
	POL *r,*temp,*list=NULL;
	while(q!=NULL){
		r=(POL*)malloc(sizeof(POL));
		r->a = (p->a) * (q->a);
		r->b = (p->b) + (q->b);  
		r->link=NULL;
		if(list==NULL)list=r;
		else temp->link=r;
		temp=r;
		q=q->link;		
	}temp->link=NULL;	
	return list;
}
POL* plus(POL *p,POL *q){//做加法,输出链表头 
	POL *temp,*list;		
	list=p;
	temp=p;
	p=p->link;//初始化，输入要保证p的第一项次数比q的第一项次数高
	while(p!=NULL&&q!=NULL){	
		if(p->b > q->b){
			temp->link=p;
			p=p->link;
			temp=temp->link; 
		}
		else if(p->b < q->b){
			temp->link=q;
			q=q->link;
			temp=temp->link;		
		}
		else {//次数相等时需要合并 
			p->a=p->a+q->a;
			temp->link=p;
			q=q->link;
			p=p->link;
			temp=temp->link; 
		} 						
	}//接上剩下的
	if(p==NULL)temp->link=q;
	else temp->link=p;
	return list;
}
int main(){	
	//数据输入阶段 
	gets(s);
	int len1=change(s,a);
	gets(s);
	int len2=change(s,b);
	POL *p=create(a,len1);
	POL *q=create(b,len2);
	//数据处理阶段 
	for(int i=1; p!=NULL; i++){
		m[i]=multi(p,q);
		p=p->link;
	} 
	for(int i=2; i<=len1; i++)
		m[1]=plus(m[1],m[i]);
	while(m[1]!=NULL){
		printf("%d %d ",m[1]->a,m[1]->b);
		m[1]=m[1]->link;
	}
	return 0;
} 

