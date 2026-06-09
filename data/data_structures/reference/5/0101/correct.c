#include<stdio.h>
#include<malloc.h>
#define MAXITEM1 50
#define MAXITEM2 200
struct data{
	int coef,exp;
}list[MAXITEM2];

int Lower(const void *p,const void *q){
	struct data *a=(struct data*)p;
	struct data *b=(struct data*)q;
	if(a->exp==b->exp) return 0;
	else if(a->exp<b->exp) return 1;
	else return -1;
}

void Same_Delete(int n){
	int i,j,k;
	int r;
	for(i=0;i<n;){
		if(list[i].coef==-1){
			i++;
			continue;
		}
		for(j=1;i+j<n;j++){
			if(list[i].exp==list[i+j].exp){
				list[i].coef+=list[i+j].coef;
				list[i+j].coef=-1;
			}
			else break;
		}
		i=i+j;
	}
}

int main(){
	int A[MAXITEM1]={},B[MAXITEM2]={};
	int a,b,n;
	int i,j;
	char c;
	for(a=0;scanf("%d%c",&A[a],&c);a++){
		if(c=='\n') break;
	};
	a++;
	for(b=0;scanf("%d%c",&B[b],&c);b++){
		if(c=='\n') break;
	};
	b++;
	for(i=0;i<a;i+=2){
		for(j=0;j<b;j+=2){
			list[n].coef=A[i]*B[j];
			list[n++].exp=A[i+1]+B[j+1];
		}
	}
	qsort(list,n,sizeof(struct data),Lower);
	Same_Delete(n);
	for(i=0;i<n;i++){
		if(list[i].coef!=-1)
			printf("%d %d ",list[i].coef,list[i].exp);
	}
	return 0;
}
