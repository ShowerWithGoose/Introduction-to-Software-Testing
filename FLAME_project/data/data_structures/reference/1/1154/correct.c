#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int n,book[20];
int a[20];
int num[20],m;
void dfs(int p){
    int i;
	if(p==n){	
		for(i = 0;i < n; i ++)
			printf("%d ",num[i]);
		printf("\n");
		return; 
	} 
	for(i=0; i < n; i++){
		if(book[i]==0){
			book[i]=1; 
			num[m++]=a[i]; 
			dfs(p+1); 
			m--; 
			book[i]=0; 
		}
	}
}
int main(){
	memset(book,0,sizeof(book));
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; i++)
		a[i-1]=i;
	m=0;
	dfs(0);
	return 0;
}

