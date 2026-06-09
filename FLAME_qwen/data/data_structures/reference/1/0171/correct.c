#include<stdio.h>
int N,i,j,a[11],o[10];

int f() {
	a[0]=1;
	int i;
	for(i=1; i<10; i++) {
		a[i]=i*a[i-1];
	}
}

void print() {
	int i=0;
	for(i=0; i<N-1; i++)
		printf("%d ",o[i]);
	printf("%d\n",o[i]);
}

void find() {
	for(i=N-2; i>=0; i--) {
		if(o[i]<o[i+1])
			break;
	}
	int k1=i;
	int temp_low=i+1;
	for(i=k1+1; i<N; i++) {
		if(o[i]>o[k1]&&o[i]<o[temp_low])
			temp_low=i;
	}
	int temp;
	temp=o[k1];
	o[k1]=o[temp_low];
	o[temp_low]=temp;

	for(j=k1+1,i=N-1; i>j; i--,j++) {
		temp=o[i];
		o[i]=o[j];
		o[j]=temp;
	}
}

int main() {
	f();
	scanf("%d",&N);
	int i;
	for(i=0; i<N; i++) {
		o[i]=i+1;
	}
	print();
	for(i=1; i<a[N]; i++) {
		find();
		print();
	}
}

