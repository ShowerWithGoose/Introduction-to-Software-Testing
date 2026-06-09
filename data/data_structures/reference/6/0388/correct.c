#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int s[500],ans[101];
int main()
{
	int a;
	int k=0;
	while(~scanf("%d",&s[k])) {
		k++;
		if(s[k-1]==-1) break;
	}
	k=k-1;
	int i=0,j=0;
	while(i<k){
		if(j>=100) {
			printf("error ");
			i++;
		}
		
		else if(s[i]==1){
			i++;
			ans[j]=s[i];
			
			j++;
			i++;
		}
		else if(s[i]==0){
			if(j==0) {
				printf("error ");
				i++;
			}
			else{
				printf("%d ",ans[j-1]);
				ans[j-1]=0;
				j--;
				i++;
			}
		}
	}
	
	
	
	
	
	return 0;
}

