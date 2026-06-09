#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int a[10000],N;
void print(int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
void number(int n,int cur){
	int i,j,flag=1;
	if(cur==n){
		N++;
		print(n); 
	}
	else{
		for(i=1;i<=n;i++){
			flag=1;
			for(j=0;j<cur;j++)
			if(a[j]==i) flag=0;
			if(flag){
			a[cur]=i;
			number(n,cur+1);	
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	number(n,0);
}


