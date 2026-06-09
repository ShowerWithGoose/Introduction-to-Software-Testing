#include<stdio.h>
int mark[11]={0};
int n;
char a[100];
void f(int,int);
int main(){
	scanf("%d",&n);
	f(0,n);
	return 0;
} 
void f(int x,int n){
	int i;
	if(n==0)
	{a[x]='\0';
	puts(a);
	return;
	}
	for(i=1;i<=n;i++){
		if(mark[i]==0)
		{mark[i]=1;
		a[x]=i+'0';
		a[x+1]=' ';
		f(x+2,n-1);
		mark[i]=0;
		}
	}
}

