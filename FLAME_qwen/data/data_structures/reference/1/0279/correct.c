#include<stdio.h>
#include<string.h>

int n,x,arrey[50000],tag[50000];
void search(int x){
	int j;
	if(x==n+1)
	{
		for(j=1;j<=n;j++){
			printf("%d ",arrey[j]);
		}
		printf("\n");
		return ; 
	}
	for(j=1;j<=n;j++){
		if(tag[j]==0){
			arrey[x]=j;
			tag[j]=1;
			search(x+1);
			tag[j]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	search(1);
	return 0;
}

