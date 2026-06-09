#include<stdio.h>
#include<stdlib.h> 
int main(){
	int a[200],b[100],i=0,top=-1;
	while(scanf("%d",&a[i])){
		if(a[i]!=-1)i++;
		else break; 
	}
	for(i=0;a[i]!=-1;i++){
		if(a[i]==1){
			top+=1;
		    b[top]=a[++i];
			}
		else if(a[i]==0&&top!=-1){
			printf("%d ",b[top]);
			top-=1;
		}
		else printf("error ");
		}
	return 0;
	}
 

