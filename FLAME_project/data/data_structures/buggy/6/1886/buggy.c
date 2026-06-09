#include <stdio.h>

int main()
{
	int s[101];
	int n=-1,i=0;
	scanf("%d",&n);
	while(n!=-1){
		if(n == 1){
			
			scanf("%d",&s[i++]);
		}else if(n == 0){
			if(s[i] == '\0'){
				printf("error ");
			}else{
				printf("%d ",&s[i--]);
			}
		}
		scanf("%d",&n);
	}
	return 0;
 } 

