#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int btr[1024];
int cov[1024];
void out(int i){
	if(!cov[i])return;
	out(2*i),out(2*i+1);
	if(!cov[2*i]&&!cov[2*i+1]){
		int h=0,val=btr[i];
		while(i)i/=2,h++;
		printf("%d %d\n",val,h);
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	int x=1,tmp;
	FOR(i,0,n){
		x=1;
		scanf("%d",&tmp);
		while(cov[x]){
			if(tmp<btr[x])x=2*x;
			else x=2*x+1;
		}
		btr[x]=tmp,cov[x]=1;
	}
	out(1);
	return 0;
}

