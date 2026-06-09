#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
void fp(int *a,int *b,int n,int dep){
	int i=1; 
	if(dep==n+1){
		for(i=1;i<=n;i++) P("%d ",a[i]);
		P("\n");
		return;
	}
	while(i<=n){
		if(b[i]==0){
			b[i]=1;
		    a[dep]=i;
		    fp(a,b,n,dep+1);
		    b[i]=0;
		}
		i++;
	}
}
int main(){
	int a[105]={0},b[105]={0},n;
	S("%d",&n);
	fp(a,b,n,1);
	return 0;
}




