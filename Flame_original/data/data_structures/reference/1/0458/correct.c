#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define eps 1e-9

void pull(int *p,int *q,int n);
void push(int *p,int *q,int n);
void permutation(int num[],int begin,int end);
int main()
{
	int N;
	int num[15];
	scanf("%d",&N);
	int begin = 1;
	for(int i = 1;i<=N;i++){
		num[i] = i;
	}
	permutation(num,begin,N);
	return 0;
}
void pull(int *p,int *q,int n){
	int temp = *q;
	for(int i = 0;i<n;i++,q--){
		*q = *(q-1);
	}
	*p = temp;
}
void push(int *p,int *q,int n){
	int temp = *p;
	for(int i = 0;i<n;i++,p++){
		*p = *(p+1);
	}
	*q = temp;
}
void permutation(int num[],int begin,int end){
	int k;
	if(begin == end){
		for(int i = 1;i<=end;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	else{
		for(k = begin;k<=end;k++){
			if(k!=begin){
				pull(&num[begin],&num[k],k-begin);
			}
			permutation(num,begin+1,end);
		
			if(k!=begin){
			push(&num[begin],&num[k],k-begin);
			}
		}
	}
}

