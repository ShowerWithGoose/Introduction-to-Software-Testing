#include <stdio.h>
#include <string.h>
#include <math.h>

int a[12];
char b[12];
int k;
void f(int m,int n);

int main(){
	scanf("%d",&k);
	f(0,k);
	
	return 0;
}

void f(int m,int n){
	int e,i;
	if(n==0){
		for(e=0;e<m;e++)  printf("%c ",b[e]);
		printf("\n");
		return;
	}
	for(i=1;i<=k;i++){
		if(a[i]==0){
			a[i]=1;
			b[m]='0'+i;
			f(m+1,n-1);
			a[i]=0;
		}
	}
}

