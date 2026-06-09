#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define N 1007
#define INF 0x3f3f3f3f
#define ll long long
#define db	double
typedef struct node {
	int top;
	int a[100];
} Stack;
Stack s;
int cmp(const void *a,const void *b) {
	int c=*(int*)a;
	int d=*(int*)b;
	return c>d;
}
int main() {
	int i,j,op,val;
	s.top=-1;
	while(1) {
		scanf("%d",&op);
		if(op==-1) {
			break;
		}
		if(op==1) {
			if(s.top==99) {
				scanf("%d",&val);
				printf("error ");
			} else {
				scanf("%d",&val);
				s.a[++s.top]=val;
			}
		}
		if(op==0) {
			if(s.top<0) {
				printf("error ");
			} else {
				printf("%d ",s.a[s.top]);
				s.top--;
			}
		}
	}
//	while(s.top--){
//		printf("%")
//	}
	return 0;
}
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 0 0 01 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 0 0 013  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 0 0 0 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 3 1 2 1 5 1 7 1 8 1 11 1 2 1 13  1 90 1 89
//1 1 0 0 0-1










