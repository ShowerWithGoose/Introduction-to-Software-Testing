#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
typedef struct Node {
	int a1;
	int a2;
	struct Node *next;
}*list;
list paixu(list L) {
	for(list q=L; q!=NULL; q=q->next) {
		int flag=0;
		for(list p=L; p!=NULL; p=p->next) {
			if(p->next==NULL) break;
			if(p->a2<p->next->a2) {
				int tmp;
				tmp=p->a1;
				p->a1=p->next->a1;
				p->next->a1=tmp;
				tmp=p->a2;
				p->a2=p->next->a2;
				p->next->a2=tmp;
				flag=1;
			}
		}
		if(!flag) break;
	}
}
list hebing(list L) {
	for(list q=L; q!=NULL; q=q->next) {
		for(list p=q->next; p!=NULL; p=p->next) {
			if(p->a2==q->a2) {
				q->a1+=p->a1;
				if(p->next==NULL) {
					list t=L;
					while(t->next!=p) {
						t=t->next;
					}
					free(p);
					p=t;
				} else {
					list t=L;
					while(t->next!=p) {
						t=t->next;
					}
					t->next=p->next;
					free(p);
					p=t;
				}
			}
		}
	}
}
int main() {
	char s1[10005]="",s2[10005]="";
	int num1[1005]= {0},num2[1005]= {0};
	list L1=NULL,p=NULL,r1=NULL;
	gets(s1);
	gets(s2);
	int n1=strlen(s1);
	int n2=strlen(s2);
	int j1=0,j2=0,sum=0;
	for(int i=0; i<n1;) {
		if(s1[i]==' ') {
			i++;
			continue;
		}
		sum=0;
		while(s1[i]>='0'&&s1[i]<='9') {
			sum=sum*10+(s1[i]-'0');
			i++;
		}
		num1[j1++]=sum;
	}
	for(int i=0; i<n2;) {
		if(s2[i]==' ') {
			i++;
			continue;
		}
		sum=0;
		while(s2[i]>='0'&&s2[i]<='9') {
			sum=sum*10+(s2[i]-'0');
			i++;
		}
		num2[j2++]=sum;
	}
//这之后错了

	for(int i=0; i<j1; i+=2) {
		p=(list)malloc(sizeof(struct Node));
		p->a1=num1[i];
		p->a2=num1[i+1];
		p->next=NULL;
		if(L1==NULL) {
			L1=p;
		} else r1->next=p;
		r1=p;
	}
	list L2=NULL,r2=NULL;
	for(int i=0; i<j2; i+=2) {
		p=(list)malloc(sizeof(struct Node));
		p->a1=num2[i];
		p->a2=num2[i+1];
		p->next=NULL;
		if(L2==NULL) {
			L2=p;
		} else r2->next=p;
		r2=p;
	}
	list p1=L1,p2=L2;
	list p3=NULL,L3=NULL,r3=NULL;
	while(p1!=NULL) {
		while(p2!=NULL) {
			p=(list)malloc(sizeof(struct Node));
			p->a1=p1->a1*p2->a1;
			p->a2=p1->a2+p2->a2;
			if(L3==NULL) {
				L3=p;
			} else r3->next=p;
			r3=p;
			p2=p2->next;
		}
		p2=L2;
		p1=p1->next;
	}

	hebing(L3);
	paixu(L3);
	for(p=L3; p!=NULL; p=p->next) {
		printf("%d %d ",p->a1,p->a2);
	}
	p=L1;
	while(p!=NULL) {
		L1=p->next;
		free(L1);
		p=L1;
	}
	p=L2;
	while(p!=NULL) {
		L2=p->next;
		free(L2);
		p=L2;
	}
	p=L3;
	while(p!=NULL) {
		L3=p->next;
		free(L3);
		p=L3;
	}
	return 0;
}


