#include <stdio.h>
int s[101];
int main()
{
	
	int n=-1,i=0;
	scanf("%d",&n);
	while(n!=-1){
		if(n == 1){
			if(i<101){
				scanf("%d",&s[i]);
				i++;
			}else{
				printf("error ");
			}
			
		}else if(n == 0){
			if(i > 0){
				i--;
				printf("%d ",s[i]);
			}else{
				printf("error ");
			}
		}
		scanf("%d",&n);
	}
	return 0;
 } 

