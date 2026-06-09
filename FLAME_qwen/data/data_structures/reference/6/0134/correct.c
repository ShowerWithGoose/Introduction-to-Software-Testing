#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ll long long
#define maxSize 1000

int n,a,num[maxSize],top=-1;

int isEmpty() {
	return top==-1;
}

int isFull() {
	return top==maxSize-1;
}

void push( int s[],	int item ) {
	if( isFull() )
		printf("error ");
	else
		s[++top]=item;
}

void pop(int s[]) {
	if( isEmpty() )
		printf("error ");
	else
		printf("%d ",s[top--]);
}

int main() {
	while(scanf("%d",&n)) {
		if(n==-1)return 0;
		else if(n==1) {
			scanf("%d",&a);
			push(num,a);
		} else if(n==0) {
			pop(num);
		}
	}
}

