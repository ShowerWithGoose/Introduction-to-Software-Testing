#include<stdio.h>
int x;
int i,j;
int fa[11];
int ans[10];
int factorial();
void print();
void find();
int main(){
	factorial();
	scanf("%d", &x) ;
	int i=0;
	for(i=0;i<x;i++){
	ans[i]=i+1;
	}
	print();
	for(i=1;i<fa[x];i++){
	find();
	print();
}
}
int factorial(){
	fa[0]=1;
	int i;
	for(i=1;i<10;i++){
		fa[i]=i*fa[i-1];
		}
	}
void print(){
	int i=0;
	for(i=0;i<x-1;i++)
		printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
	}
void find(){
	for(i=x-2;i>=0;i--){
		if(ans[i]<ans[i+1])
		break;
	}
	int k1=i;
	int tl=i+1;
	for(i=k1+1;i<x;i++){
		if(ans[i]>ans[k1]&&ans[i]<ans[tl])
		tl=i;
	}
	int t;
	t=ans[k1];
	ans[k1]=ans[tl];
	ans[tl]=t;
	for(j=k1+1,i=x-1;i>j;i--,j++){
		t=ans[i];
		ans[i]=ans[j];
		ans[j]=t;
	}
}

