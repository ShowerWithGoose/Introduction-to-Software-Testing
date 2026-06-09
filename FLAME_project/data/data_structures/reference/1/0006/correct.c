#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

int n, *p;
void f(int k, int* p, int* q);

int main(){
	scanf ("%d", &n);
	p = (int*)malloc(n);
	for (int i=0; i<n; i++) p[i]=i+1;
	f(n, NULL, p);
	free(p);
	return 0;
}

void f(int k, int* p, int* q){
	if (k==1){
		for (int i=0; i<n-1; i++) printf ("%d ", p[i]);
		printf ("%d\n", q[0]);
		return;
	}
	int *p1, *q1;
	for (int i=0; i<k; i++){
		p1=(int*)malloc(n-k+1);
		for (int j=0; j<n-k; j++) p1[j]=p[j];
		p1[n-k]=q[i];
		q1=(int*)malloc(k);
		for (int j=0,l=0; l<k; l++){
			if (l==i) continue;
			q1[j]=q[l];
			j++;
		}
		f(k-1, p1, q1);
		free(p1);free(q1);
	}
}



