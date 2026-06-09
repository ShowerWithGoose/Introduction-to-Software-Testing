#include<stdio.h>
#include<string.h>
int len,n,j,x;
int rem[10],fin[10];
int a[11];
void print(){
	for(int i=0;i<n;i++){
		printf("%d ",fin[i]);
	}
	printf("\n");
}
void DFS(int x){
	if(x==n)
	print();
	for(int i=0;i<n;i++){
		if(a[i]==0){
			a[i]=1;
			fin[x]=rem[i];
			DFS(x+1);
			a[i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(j=0;j<n;j++){
		rem[j]=j+1;
	}
	DFS(0);
	return 0;
}

