#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
	int n,k;
	while(1){
		scanf("%d",&n);
		int i=0,j=0;
		if(n==1){
		    if(i<=99){
			    scanf("%d",&k); 
			    a[i]=k;i++;}
		}
		else if(n==0){
			if(i>=0&&i<=99){
			    printf("%d ",a[i]);
			    i--;
			}
			else printf("error ");
		}
		else if(n==-1)
		    break;
	}
}

