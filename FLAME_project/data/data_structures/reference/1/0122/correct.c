#include<stdio.h>
#include<string.h>
	int i,n,c[15],d[15];
	int flag[15];

void f(int x){
	int i;
	if(x>=n){
		for(i=0;i<n;i++){
			printf("%d ",d[i]);
		}printf("\n");
		
	}
	else{
		for(i=0;i<n;i++)
			if(flag[i]==0){
				d[x]=c[i];
				flag[i]=1;
				f(x+1);
				flag[i]=0;	
		
			
		}
	
}return;
}
int main(){
memset(flag,0,sizeof(flag));

	scanf("%d",&n);
	for(i=0;i<n;i++){
		c[i]=i+1;
	}
	f(0);
	return 0;
} 



