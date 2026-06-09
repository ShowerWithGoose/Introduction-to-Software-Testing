#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct _mul{
	int a;
	int b;
	struct _mul *next;
};
typedef struct _mul mul;
int tran(char X[],mul *mX){
	int a,b,i=0,n=0,flag;
	while(X[i]!='\0'){
		a=0;
		b=0;
		flag=0;
		if(X[i]=='-'){
			flag=1;
			i++;
		}
		while(X[i]!=' '){
			a=a*10+(X[i]-'0');
			i++;
		}
		i++;
		while(X[i]!=' '&&X[i]!='\0'){
			b=b*10+(X[i]-'0');
			i++;
		}
		i++;
		if(flag){
			a=-a;
		}
		mX[n].a=a;
		mX[n].b=b;
		n++;
	}
	return n;
}
void multiply(int a,int b,mul *A,mul *B,mul *C){
	int i,j,n=0;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			C[n].a=A[i].a*B[j].a;
			C[n].b=A[i].b+B[j].b;
			n++;
		}
	}
}
int cmp(const void *p1,const void *p2){
	mul *f1=(mul*)p1;
	mul *f2=(mul*)p2;
	return f2->b-f1->b;
}
int main()
{
	mul A[100],B[100],C[10000],*p;
	char mulA[10000],mulB[10000];
	int nA,nB,i;
	gets(mulA);
	gets(mulB);
	nA=tran(mulA,A);
	nB=tran(mulB,B);
	multiply(nA,nB,A,B,C);
	qsort(C,nA*nB,sizeof(mul),cmp);
	p=&C[0];
	for(i=0;i<nA*nB-1;i++){
		C[i].next=&C[i+1];
	}
	while(p->next!=NULL){
		while(p->next->b==p->b){
			p->a+=p->next->a;
			p->next=p->next->next;
		}
		p=p->next;
	}
	p=&C[0];
	if(p->a!=0)
		printf("%d %d ",p->a,p->b);
	while(p->next!=NULL){
		p=p->next;
		if(p->a==0)
			continue;
		printf("%d %d ",p->a,p->b);
	}
	return 0;
} 

