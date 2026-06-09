#include<stdio.h>              
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h> 
char s1[1003],s2[1003];
typedef struct node* polynomial;
struct node{
	int coef;
	int expon;
	polynomial next;
};
int getnum(int start,char s[]){
	int num = 0,i;
	for(i = start; s[i]!='\0'&&s[i]!=' ';i ++){
		num = num * 10;
		num = num + (s[i] - '0');
	}
	return num;
}
int main(void)
{
	int i,clock = 0;
	polynomial head1=NULL,head2=NULL,p,q,ans=NULL,add,rear,search;//q作定位之用 ,指向链表尾部 
	gets(s1);
	for(i = 0;i <= strlen(s1) - 1;i ++){
		clock ++;
		if(clock%2==1){
			p = (polynomial)malloc(sizeof(struct node));
			p->coef = getnum(i,s1);
		}	
		else {
			p->expon = getnum(i,s1);
			if(head1==NULL){
				head1 = p;
				q = head1;
				q->next = NULL;
			}
			else{
				q->next = p;
				q = p;
				q->next = NULL;
			}
		}
		while(s1[i]>='0'&&s1[i]<='9') i++;
	}
	gets(s2);
	clock = 0;
	for(i = 0;i <= strlen(s2) - 1;i ++){
		clock ++;
		if(clock%2==1){
			p = (polynomial)malloc(sizeof(struct node));
			p->coef = getnum(i,s2);
		}	
		else {
			p->expon = getnum(i,s2);
			if(head2==NULL){
				head2 = p;
				q = head2;
				q->next = NULL;
			}
			else{
				q->next = p;
				q = p;
				q->next = NULL;
			}
		}
		while(s2[i]>='0'&&s2[i]<='9') i++;
	}//链表的搭建完成 head1 head2
	p = head1;
	q = head2;
	for(q = head2;q != NULL;q = q->next){
		add = (polynomial)malloc(sizeof(struct node));//新的节点 ,rear指向链表末尾 ,ans是表头 
		add->coef = (p->coef)*(q->coef);
		add->expon = (p->expon) + (q->expon);
		add->next = NULL;
		if(ans == NULL){
			ans = add;
			rear = add;
			ans->next = NULL;
		}
		else{
			rear->next = add;
			rear = add;
			rear->next = NULL;
		}
	}
	for(p = head1->next;p !=NULL;p = p->next){
		for(q = head2;q != NULL;q = q->next){
			add = (polynomial)malloc(sizeof(struct node));
			add->coef = (p->coef)*(q->coef);
			add->expon = p->expon + q->expon;
			add->next = NULL;
			for(search = ans;search != NULL;search = search->next){
				if(search->expon == add->expon){
					search->coef = search->coef + add->coef;
					break;
				}
				else if(search->expon > add->expon&&search->next!=NULL&&search->next->expon < add->expon){
					add->next = search->next;
					search->next = add;
					break;
				}
				else if(search->expon > add->expon&&search->next == NULL){
					search->next = add;
					add->next = NULL;
					break;
				}
			}
		}
	}
	for(p = ans;p != NULL;p = p->next){
		if(p->coef!=0) printf("%d %d ",p->coef,p->expon);
	}
	return 0;
}



