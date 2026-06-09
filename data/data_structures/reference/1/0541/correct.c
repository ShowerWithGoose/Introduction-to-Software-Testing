#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int num[10+5],flag[10+5],n; 

void rank(int x){
	int i;
	
	if(x==n+1){
		for(i=1;i<=n;i++) printf("%d ",num[i]);
		
		printf("\n");
		
		return;
	} 
	
	for(i=1;i<=n;i++){
		if(flag[i]==0){
			num[x]=i;
			
			flag[i]=1;
			
			rank(x+1);
			
			flag[i]=0;
		}
	}
	return;
}

int main(){
	scanf("%d",&n);
	
	rank(1);
	
	return 0;
}



