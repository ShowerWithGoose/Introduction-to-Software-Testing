#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct mul {
	int a;
	int e;
} mul1[500]= {0},mul2[500]= {0},mul3[250000]= {0};
int cmp(const void*a,const void*b) {
	return (*(struct mul*)a).e<(*(struct mul*)b).e?1:-1;
}
void add(struct mul x[],int n) {
	for(int i=0; i<n-1; i++)
		if(x[i].e==x[i+1].e) {
			x[i+1].a=x[i].a+x[i+1].a;
			x[i].a=0;
			x[i].e=-1;
		}
}
int main() {
	int i=0,j=0,k=0;
	char c='x';
	for(i=0; c!='\n'; i++)
		scanf("%d%d%c",&mul1[i].a,&mul1[i].e,&c);
	int n1=i;
	char b='x';
	for(i=0; b!='\n'; i++)
		scanf("%d%d%c",&mul2[i].a,&mul2[i].e,&b);
	int n2=i;
	for(i=0; i<n1; i++)
		for(j=0; j<n2; j++) {
			mul3[k].a=mul1[i].a*mul2[j].a;
			mul3[k++].e=mul1[i].e+mul2[j].e;
		}
	qsort(mul3,n1*n2,sizeof(struct mul),cmp);
		for(i=0;i<n1*n2;i++)
	//printf("%d %d ",mul3[i].a,mul3[i].e);
	add(mul3,n1*n2);
//	printf("\n");
	qsort(mul3,n1*n2,sizeof(struct mul),cmp);
	for(i=0;i<n1*n2&&mul3[i].a!=0;i++)
	printf("%d %d ",mul3[i].a,mul3[i].e);
	return 0;
}

