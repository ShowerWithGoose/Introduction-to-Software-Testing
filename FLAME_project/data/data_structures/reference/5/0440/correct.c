#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct Poly{
	int coef,expo;
	struct Poly *next;
};
typedef struct Poly poly;
typedef struct Poly *polyptr;

polyptr y;

polyptr search(polyptr p,polyptr head){
	polyptr i=head;//要输出链表的头结点！不存数据
	for(i=head;(i->next)!=NULL;i=i->next){
		if(p->expo==i->next->expo){
			//如果相等，那么直接在i的地址对应的coef上加p的coef
			i->next->coef+=p->coef;
			free(p);
			return y;
		}else if(p->expo>(i->next)->expo){
			return i;//返回i->next的前一个指针
		}
		
	}
	if(i->next==NULL){
			return i; 
		} 
	
}

void insert(polyptr p,polyptr head){
	if(search(p,head)==y){
		return ;
	}else{		
		p->next=search(p,head)->next;
		search(p,head)->next=p;
		return ;
	}
}

int main(){
	int a[10000][2]={0},b[10000][2]={0},i=1,num=0;
	int c=0,e=0;
	/*
	scanf("%d%d",a[0][0],a[0][1]);
	while(getchar()!='\n'){
		scanf("%d%d",a[i][0],a[i][1]);
		i++;//i最后为多项式a的项数
	}
	num=i;
	*/

	int j=0,n=0;
	char s[10000],s1[10000];
	gets(s);
	while(s[j]){
		while(s[j]<'0')j++;
		while(s[j]>='0'){
			a[n][0]=a[n][0]*10+s[j]-'0';
			j++;
		}
		while(s[j]<'0')j++;
		while(s[j]>='0'){
			a[n][1]=a[n][1]*10+s[j]-'0';
			j++;
		}
		n++;
	}
	num=n;
	j=0,n=0;
	
	gets(s1);
	while(s1[j]){
		while(s1[j]<'0')j++;
		while(s1[j]>='0'){
			b[n][0]=b[n][0]*10+s1[j]-'0';
			j++;
		}
		while(s1[j]<'0')j++;
		while(s1[j]>='0'){
			b[n][1]=b[n][1]*10+s1[j]-'0';
			j++;
		}
		n++;
	}
	
	/*
	for(i=0;i<num;i++){
		printf("%d %d ",a[i][0],a[i][1]);
	}
	*/
	polyptr head,end,node;
	head=(polyptr)malloc(sizeof(poly));
	end=head;
	j=0;
	while(j<n){	
		c=b[j][0];
		e=b[j][1];
//		printf("%d %d ",c,e);
		
		for(i=0;i<num;i++){
			if(head==end){
				node=(polyptr)malloc(sizeof(poly));
				node->coef=c*a[i][0];
				node->expo=e+a[i][1];
				end->next=node;
				end=node;
				end->next=NULL;
			}else{
			//	printf("1\n");
				node=(polyptr)malloc(sizeof(poly));
				node->coef=c*a[i][0];
				node->expo=e+a[i][1];
				insert(node,head);//这里的问题
			}
			
		}
		//	printf("%d\n",j);
			j++;
	}
	polyptr p;
	p=head;
	//printf("%d %d ",end->coef,end->expo);
	while(p->next!=NULL){
		p=p->next;
		printf("%d %d ",p->coef,p->expo);
	}
	return 0;
}

