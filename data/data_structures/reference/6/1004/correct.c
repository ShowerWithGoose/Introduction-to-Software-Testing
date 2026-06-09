#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int a[1000],b[100];
int main(){
	int i=0,m,n=0,k=0;
	while(1){
		scanf("%d",&m);
		if(m!=-1){
			a[i]=m;
			i++;
			n++;
		}
		else if(m==-1){
			break;
		}
	}
	a[n]=-1;
	for(i=0;i<n+1;i++){
		
		if(a[i]==1){
			if(k>=100){
				printf("error ");
			}
			else{
				b[k]=a[i+1];
				k++;
			}
		}
		else if(a[i]==0){
			if(k<1){
				printf("error ");
			}
			else{
				printf("%d ",b[k-1]);
				k--;
			}
		}
		else if(a[i]==-1){
			break;
		}
	}
return 0;
}


