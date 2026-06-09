#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct Polynomial {
	int a;//系数
	int n;//指数
	struct Polynomial *next;
} Poly, *PPoly;

PPoly MonomialRead(int a,int n) {
	PPoly p0=(PPoly)malloc(sizeof(Poly));
	p0->a=a;
	p0->n=n;
	p0->next=NULL;
	return p0;
}

PPoly PolyRead() {
	PPoly p1=(PPoly)malloc(sizeof(Poly)),p0=p1;
	int a,n;
	scanf("%d%d",&p1->a,&p1->n);
	p1->next=NULL;
	if(getchar()!='\n'){
	while(scanf("%d%d",&a,&n)==2) {
		if(a!=0) {
			p1->next=MonomialRead(a,n);
			p1=p1->next;
		}
		if(getchar()=='\n') break;
	}
	} 
	return p0;
}

PPoly MonomialMultiply(PPoly p1,PPoly p2) {
	PPoly p3=(PPoly)malloc(sizeof(Poly));
	p3->a=p1->a*p2->a;
	p3->n=p1->n+p2->n;
	p3->next=NULL;
	return p3;
}

void PolyAdd(PPoly pa,PPoly pb) {
	PPoly p1=pa,p2=pb,p0=NULL;
	while(p1->next!=NULL&&p1->next->n>p2->n) { //p1 > p2 >= p1->next
		p1=p1->next;
	}
	if(p1->next==NULL||p1->next->n<p2->n) {
		p2->next=p1->next;
		p1->next=p2;
	} else if(p1->next->n==p2->n) {
		p1->next->a+=p2->a;
		free(p2);
		if(p1->next->a==0) {
			p0=p1->next;
			p1->next=p1->next->next;
			free(p0);
		}
	}
}

PPoly MultiplyPoly(PPoly pa,PPoly pb) {
	PPoly p0,p1=pa,p2=pb;
	int flag=1;
	p0=MonomialMultiply(p1,p2);
	p2=p2->next;
	
	for(p1=pa; p1!=NULL; p1=p1->next) {
		for(p2=pb; p2!=NULL; p2=p2->next) {
			if(flag){
				flag=0;
				continue;
			}
			PPoly p4=MonomialMultiply(p1,p2);
			PolyAdd(p0,p4);
		}
	}
	return p0;
}

void PrintPoly(PPoly pa) {
	PPoly p1=pa;
	printf("%d %d ",p1->a,p1->n);
	p1=p1->next;
	while(p1!=NULL) {
		printf("%d %d ",p1->a,p1->n);
		p1=p1->next;
	}
}

int main() {
	PPoly p1,p2,p3;
	p1=PolyRead();
	p2=PolyRead();
	p3=MultiplyPoly(p1,p2);
	PrintPoly(p3);
	return 0;
}

