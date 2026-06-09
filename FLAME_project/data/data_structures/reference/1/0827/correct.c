#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
int num[11]={},deal[11]={},mark[11]={};
void rank(int begin,int end){
	int i;
	if(begin==end){
		for(i=0;i<end;i++){
			printf("%d ",deal[i]);
		}
		printf("\n");
	}
	else{
		for(i=0;i<end;i++){
			if(mark[i]==0){
				deal[begin]=num[i];
				mark[i]=1;
				rank(begin+1,end);
				mark[i]=0;
			}
		}
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	num[i]=i+1;
	rank(0,n);
}


