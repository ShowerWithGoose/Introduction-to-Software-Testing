#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

void f(int n,int k,int a[],int b[]){
	if(k>n){
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=1){
			a[k]=i;
			b[i]=1;
			f(n,k+1,a,b);
			b[i]=0;
		}
	}
} 
int main(){
	int n,a[12]={0},b[12]={0};
	scanf("%d",&n); 
	f(n,1,a,b); 
}


