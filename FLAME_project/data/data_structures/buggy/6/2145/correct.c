#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
	int n,k;
			int i=0,j=0;
	while(1){
		scanf("%d",&n);

		if(n==1){
		    if(i<=99){
			    scanf("%d",&k); 
			    a[i++]=k;
				
				}
			continue;
		}
		else if(n==0){
			if(i>0&&i<=99){
			    printf("%d ",a[--i]);
			    
			}
			else printf("error ");
			continue;
		}
		else if(n==-1)
		    break;
	}
	return 0;
}

