#include<stdio.h>
#include<string.h>
#include<math.h> 
int a[11],b[11],biaoji[11];
int pailie(int n,int k){
   for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	if(k!=n){
		for(int j=0;j<n;j++){
		if(biaoji[j]==0){
		b[k]=a[j];
		biaoji[j]=1;
		pailie(n,k+1);
		biaoji[j]=0;
		}
	}}
	else{
		for(int i=0;i<n;i++){
			printf("%d ",b[i]);
		
		}
		printf("\n");} 
}
int main(){
    int n,k; 
	k=0; 	
	scanf("%d",&n);
   pailie(n,k);
}

