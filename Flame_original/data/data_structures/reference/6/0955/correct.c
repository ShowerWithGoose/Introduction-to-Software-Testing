#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,temp,i=0;
	struct zhan{
		int x;
	};
	struct zhan f[100];
	scanf("%d",&n);
	while(n!=-1){
		if(n==1){
			if(i==99){
			printf("error ");
			scanf("%d",&temp);
		    }
	        else
			{scanf("%d",&f[i].x);
			i++;
			}}
	    if(n==0){
			if(i==0)
			printf("error ");
			else{
				i--;
				printf("%d ",f[i].x);
				
			}
		}
	scanf("%d",&n);
	}
	return 0;
}

