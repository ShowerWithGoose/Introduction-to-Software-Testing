#include<stdio.h>
int mark[11]={0};
int N;
char x[100];
void f(int,int);
int main(){
	scanf("%d",&N);
	f(0,N);
	return 0;
} 
void f(int m,int n){
	int i;
	if(n==0)
	{x[m]='\0';
	puts(x);
	return;
	}
	for(i=1;i<=N;i++){
		if(mark[i]==0)
		{mark[i]=1;
		x[m]=i+'0';
		x[m+1]=' ';
		f(m+2,n-1);
		mark[i]=0;
		}
	}
}

