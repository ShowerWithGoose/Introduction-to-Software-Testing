#include <stdio.h>
#include<string.h>
int num() {
	int a;
	scanf("%d",&a);
	return a;
}
char fu() {
	char b;
	do {
		scanf("%c",&b);
	} while(b==' ');
	return b;
}
int suan(char b1,char b2) {
	if(b1=='*'||b1=='/') return 0;
	else if(b2=='*'||b2=='/') return 1;
	else return 0;
}
int cc(int x,char b,int y) {
	if(b=='+') return x+y;
	if(b=='-') return x-y;
	if(b=='*') return x*y;
	if(b=='/') return x/y;
}
int main() {
	int i,j,k;
	char m,n;
	i=num();
	m=fu();
	if(m == '=') printf("%d",i);
	else {
		j=num();
		n=fu();
		if(n =='=') printf("%d",cc(i,m,j));
		else {
			while(n != '=') {
				k=num();
				if(suan(m,n)==0) {
					i=cc(i,m,j);
					j=k;
					m=n;
				} else j=cc(j,n,k);
				n=fu();
			}
			printf("%d",cc(i,m,j));
		}

	}
	return 0;
}


