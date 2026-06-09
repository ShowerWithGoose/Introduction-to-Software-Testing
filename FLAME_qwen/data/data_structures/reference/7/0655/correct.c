#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
int a[1000001];
void build(int m){
	int i2=1;
	while(a[i2]!=-1){
		if(a[i2]>m) i2=2*i2;
		else i2=2*i2+1;
	}
	a[i2]=m;
}
void leave(int m,int depth){
	if(a[m*2]!=-1) leave(m*2,depth+1);
	if(a[m*2+1]!=-1) leave(m*2+1,depth+1);
	if(a[m*2]==-1&&a[m*2+1]==-1) printf("%d %d\n",a[m],depth);
}
int main(){
	int i,j,k;
	int n,m;
	for(i=1;i<=1000000;i++) a[i]=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		if(i!=0) build(m);
		else a[1]=m;
	}
	leave(1,1);
	getchar();getchar();
    return 0;
}


