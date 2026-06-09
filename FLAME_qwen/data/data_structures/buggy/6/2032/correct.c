#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1; 
int main()
{	scanf("%d",&op);
	while(op==1||op==0){
		
		if(op==1){
			if(i>=100){
				printf("error ");
			}else{
				scanf("%d",&s[++i]);
				
			}
			
		}else if(op==0){
			
			if(i<0){
				printf("error ");
			}else{
				printf("%d ",s[i--]);
			
			}
			
		}
		
		scanf("%d",&op);
	}
 return 0;
}

