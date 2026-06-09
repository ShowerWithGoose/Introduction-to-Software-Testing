#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10
#define max 11 
int a[max],book[max],n;
void  dfs(int step){ 
	int i;
	if(step==n+1){     
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");	
		return ;
	}
	 for(int i=1;i<=n;i++){
		if(book[i]==0){ 
			a[step]=i;
			book[i]=1;		
			dfs(step+1);				
			book[i]=0;		
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	dfs(1);  
	return 0;
}



