#include<stdio.h>
#include<string.h>
int max,used[12],s[12];
void qpl(int N,int s[],int use,int used[]){
	if(N==1){
		for(int i=1;i<=max-1;i++)printf("%d ",used[i]);
		if(use==-1)printf("1");
		else printf("%d\n",use);
		return;
	}
	int temp[12],j=0;
	memset(temp,0,48);
	for(int i=1;i<=N;i++)if(s[i]!=use)temp[++j]=s[i];
	N=j;
	for(int i=1;i<=N;i++){
		used[max-N+1]=temp[i];
		qpl(N,temp,temp[i],used);
	}
}
int main(){
	scanf("%d",&max);
	for(int i=1;i<=max;i++)s[i]=i;
	qpl(max,s,-1,used);
}
