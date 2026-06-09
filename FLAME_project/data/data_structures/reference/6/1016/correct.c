#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
    {
    	int a[100],s[100];
    	int i=0,k=-1;
    	scanf("%d",&s[0]);
    	i++;
    	while(s[i-1]!=-1) {
    		scanf("%d",&s[i]);
    		i++;
		}
		for(i=0;s[i]!=-1;i++){
			if(s[i]==1){
			   if(k==99) printf("error "),i=i+1;
			   else if(k<99){
			   	a[++k]=s[i+1];
			   	i=i+1;
			   }
			}
		
			if(s[i]==0){
				if(k==-1){
					printf("error ");
					
				}
				if(k!=-1){
					printf("%d ",a[k--]);
					
				}
			}
		}
		return 0;
	}

