#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct l{
	long long x;
	long long z;
	struct l *next;
} list;
list h1,h2,h3;
char s[999];
long long num[5];
void BUILD_LIST(list*);
void SEARCH(long long,long long,list*);
int main()
{
	long long tx,tz;
	list *p1,*p2,*p;
	BUILD_LIST(&h1);
	BUILD_LIST(&h2);
	for(p1=(h1.next);p1!=NULL;p1=(p1->next)){
		for(p2=(h2.next);p2!=NULL;p2=(p2->next)){
			tx = (p1->x)*(p2->x);
			tz = (p1->z)+(p2->z);
			SEARCH(tx,tz,&h3);
		}
	}
	p = h3.next;
	while(p!=NULL){
		printf("%lld %lld ",p->x,p->z);
		p = p->next;
	}
	return 0;
}

void SEARCH(long long tx,long long tz,list* p1)
{
	list *p,*pre,*tp;
	p = (p1->next);
	pre = p1;
	while(p!=NULL){
		if((p->z)<tz){
			tp = (list*)malloc(sizeof(list));
			tp->x = tx;
			tp->z = tz;
			pre->next = tp;
			tp->next = p;
			return;
		}
		else if((p->z)==tz){
			p->x += tx;
			return;
		}
		else if((p->z)>tz){
			pre = p;
			p = p->next;
		}
	}
	if(p==NULL){
		tp = (list*)malloc(sizeof(list));
		tp->x = tx;
		tp->z = tz;
		tp->next = NULL;
		pre->next = tp; 
		return;
	}
	
}

void BUILD_LIST(list* f)
{
	list *pre,*p;
	long long tem=0;
	int i,tail=1;
	gets(s);
	pre = f;
	for(i=0;i<strlen(s);i++){
		if(isdigit(s[i])!=0){
			tem = tem*10+s[i]-'0';
			if(isdigit(s[i+1])==0){
				num[tail] = tem;
				tem = 0;
				tail++;
				if(tail==3){
					p = (list*)malloc(sizeof(list));
					p->x = num[1];
					p->z = num[2];
					p->next = NULL;
					pre->next =  p;
					pre = p;
					tail = 1;
				}
			}
		}
	}
	memset(s,0,998);
	return;
}














