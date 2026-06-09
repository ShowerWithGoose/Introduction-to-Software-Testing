#include<stdio.h>
int mark[11]={0};
int n;
char path[100];
void f(int,int);
int main(){
	scanf("%d",&n);
	f(0,n);
	return 0;
} 
void f(int N,int n){
	int i;
	if(n==0)
	{path[N]='\0';
	puts(path);
	return;
	}
	for(i=1;i<=n;i++){
		if(mark[i]==0)
		{mark[i]=1;
		path[N]=i+'0';
		path[N+1]=' ';
		f(N+2,n-1);
		mark[i]=0;
		}
	}
}

