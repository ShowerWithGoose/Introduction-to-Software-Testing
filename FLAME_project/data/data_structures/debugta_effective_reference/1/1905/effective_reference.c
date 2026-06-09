#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define eps 1e-9

void pull(int *p,int *q,int n);
void push(int *p,int *q,int n);
void permutation(int save[],int begin,int end);
int main()
{
	int n;
	int save[15];
	scanf("%d",&n);
	int begin = 1;
	for(int i = 1;i<=n;i++){
		save[i] = i;
	}
	permutation(save,begin,n);
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
void permutation(int save[],int begin,int end){
	int i;
	if(begin == end){
		for(int i = 1;i<=end;i++){
			printf("%d ",save[i]);
		}
		printf("\n");
	}
	else{
		for(i = begin;i<=end;i++){
			if(i!=begin){
				pull(&save[begin],&save[i],i-begin);
			}
			permutation(save,begin+1,end);
		
			if(i!=begin){
			push(&save[begin],&save[i],i-begin);
			}
		}
	}
}

