#include<stdio.h>
int n[20]= {0,1,2,3,4,5,6,7,8,9,10};
int m[20]= {0,0,0,0,0,0,0,0,0,0,0,};

void p(int b,int a);
int main() {
	int t;
	int j=1;
	scanf("%d",&t);
	p(t,j);
	return 0;
}
void p(int b,int j) {
	int c,i,l;
	if(j==b+1) {
		for(l=1; l<=b; l++) {
			printf("%d ",m[l]);
		}
		printf("\n");
	}
	for(i=1; i<=b; i++) {
		if(n[i]!=0) {
			m[j]=n[i];
			c=n[i];
			n[i]=0;
			p(b,j+1);
			n[i]=c;

		}
	}
}

