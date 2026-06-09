#include<stdio.h>
char fu[10000];
int shu[10000],sz[10000];
int main(){
	int isz=0,ishu=0,ifu=0,i=-1;
	scanf("%d ",&sz[++i]);
	while((sz[++i]=getchar())!='='){
		scanf("%d ",&sz[++i]);
	}
	shu[0]=sz[0];
	for(isz=1;sz[isz]!='=';isz+=2){
		if(sz[isz]=='*')shu[ishu]*=(sz[isz+1]);
		if(sz[isz]=='/')shu[ishu]/=(sz[isz+1]);
		if(sz[isz]=='+'||sz[isz]=='-'){
			fu[++ifu]=sz[isz];
			shu[++ishu]=sz[isz+1];
		}
	}
	for(i=1;i<=ifu;i++){
		if(fu[i]=='+')shu[0]+=shu[i];
		else shu[0]-=shu[i];
	}printf("%d",shu[0]);
}
