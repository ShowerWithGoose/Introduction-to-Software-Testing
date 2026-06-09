#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct multi{
	int mu;
	int lt;
} m[2000],n[2000],p[2000];

int com(const void*x1,const void*x2){
	struct multi *a=(struct multi*)x1;
	struct multi *b=(struct multi*)x2;
	return b->lt-a->lt;
}

int main(){
	int i=0,j=0,k=0;
	int num1=0;
	int num2=0;
	char c;
	do{
		scanf("%d%d%c",&m[num1].mu,&m[num1].lt,&c);
		num1++;
	}while(c!='\n');
	do{
		scanf("%d%d%c",&n[num2].mu,&n[num2].lt,&c);
		num2++;
	}while(c!='\n');
	qsort(m,num1,sizeof(m[0]),com);
	qsort(n,num2,sizeof(n[0]),com);
	for(i=0;i<num1;i++){
		for(j=0;j<num2;j++){
			p[k].mu=m[i].mu*n[j].mu;
			p[k].lt=m[i].lt+n[j].lt;
			k++;
		}
	}
	i=0;
	j=0;
	qsort(p,k,sizeof(p[0]),com);
	for(i=0;i<k;i++){
		if(p[i].lt==p[i+1].lt&&p[i].lt!=0){
			p[i+1].mu+=p[i].mu;
			p[i].mu=0;
		}
	}
	i=0;
	qsort(p,k,sizeof(p[0]),com);
	for(i=0;i<k;i++){
		if(p[i].mu!=0){
			printf("%d %d ",p[i].mu,p[i].lt);
		}
	}
	return 0;
}

