#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[10];
void f(int m,int n){
	int i,j,flag=1;
	if(m==n){
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	else{
		for(j=1;j<=m;j++){
			flag=1;
			for(int k=0;k<n;k++){
				if(a[k]==j) flag=0;
			}
			if(flag!=0){
				a[n]=j;
				f(m,n+1);
			}
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) 
	a[i]=i+1;
	f(n,0); 
return 0;
}









