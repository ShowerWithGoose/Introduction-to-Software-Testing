#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//int范围：2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
int mark[11]={0};
char stack[11];
void rank(int m,int n);//m记录下一个要生成的全排列数字应放在stack中的位置，n表示还有几个数字需要生成
int N;

int main(){
	scanf("%d",&N);
	rank(0,N);
	return 0;
}

void rank(int m,int n){
	int i;
	if(n==0){
		stack[m]='\0';
		for(int j=0;j<N-1;j++){
			printf("%c ",stack[j]);
		}
		printf("%c\n",stack[N-1]);
		return;
	}
	for(i=1;i<=N;i++){
		if(mark[i]==0){
			mark[i]=1;
			stack[m]='0'+i;
			rank(m+1,n-1);
			mark[i]=0;
		}
	}
}

