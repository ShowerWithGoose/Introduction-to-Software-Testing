#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct _line{
	long long int x;
	long long int n;
	struct _line* link;
}line, *Pline;

int main(){
	long long int i, j, k, k1, k2, a, b, flag=0, temp1, temp2;
	char m;
	Pline list1=NULL, p, p1, p2, q, q1, q2, r, list2=NULL, list3=NULL;
	do{
		scanf("%lld%lld%c", &a, &b, &m);
		q = (Pline)malloc(sizeof(line));
		q->x = a;
		q->n = b;
		q->link = NULL;
		if(list1 == NULL){
			list1 = p = q;
		}
		else{
			p->link = q;
			p = p->link;
		}
		}while(m!='\n');
	do{
		scanf("%lld%lld%c", &a, &b, &m);
		q = (Pline)malloc(sizeof(line));
		q->x = a;
		q->n = b;
		q->link = NULL;
		if(list2 == NULL){
			list2 = p = q;
		}
		else{
			p->link = q;
			p = p->link;
		}
		}while(m!='\n');
	
//相乘	
	p1 = list1; p2 = list2;
	for(p1=list1; p1->link!=NULL; q1=p1, p1=p1->link){
		for(p2=list2; p2->link!=NULL; q2=p2, p2=p2->link){
			 q = (Pline)malloc(sizeof(line));
		q->x = p1->x*p2->x;
		q->n = p1->n+p2->n;
		q->link = NULL;
		if(list3 == NULL){
			list3 = p = q;
		}
		else{
			p->link = q;
			p = p->link;
		}
		}
		 q = (Pline)malloc(sizeof(line));
		q->x = p1->x*p2->x;
		q->n = p1->n+p2->n;
		q->link = NULL;
		if(list3 == NULL){
			list3 = p = q;
		}
		else{
			p->link = q;
			p = p->link;
		}
	}
	for(p2=list2; p2->link!=NULL; q2=p2, p2=p2->link){
			 q = (Pline)malloc(sizeof(line));
		q->x = p1->x*p2->x;
		q->n = p1->n+p2->n;
		q->link = NULL;
		if(list3 == NULL){
			list3 = p = q;
		}
		else{
			p->link = q;
			p = p->link;
		}
		}
		 q = (Pline)malloc(sizeof(line));
		q->x = p1->x*p2->x;
		q->n = p1->n+p2->n;
		q->link = NULL;
		if(list3 == NULL){
			list3 = p = q;
		}
		else{
			p->link = q;
			p = p->link;
		}
	
	//链表排序 
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	p = list3;
	for(p=list3; p->link!=NULL; p=p->link){
		a = p->n;
		for(q=p->link; q->link!=NULL; q=q->link){
			if(q->n>a){
				q1 = q;
				flag = 1;
			}
		}
		if(q->n>a){
			q1 = q;
			flag = 1;
		}
		if(flag == 1){
			temp1 = p->n;
			p->n = q1->n;
			q1->n = temp1;
			temp2 = p->x;
			p->x = q1->x;
			q1->x = temp2; 
		}
		flag = 0;
	}
	

	//合并相同指数 
	if(list3->link != NULL){
	for(p=list3, q=p->link; q->link!=NULL; r=p, p=p->link,q=q->link){
		if(p->n == q->n){
			p->x = p->x + q->x;
			p->link = q->link;
			p = r;
		}
	}
		if(p->n == q->n){
			p->x = p->x + q->x;
			p->link = NULL;
		}
	}
		
		for(p=list3; p->link!=NULL; p=p->link){
			printf("%lld %lld ", p->x, p->n);
		}
		printf("%lld %lld", p->x, p->n);
}

