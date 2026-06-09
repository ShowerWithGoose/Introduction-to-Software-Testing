#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int a,b,c[100],flag=-1; 
int main()
{
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			scanf("%d",&b);
			flag++;
			c[flag]=b;
		}
		if(a==0){
			if(flag<0||flag>99)
				printf("error ");
			else{
				printf("%d ",c[flag]);
				c[flag]=0;
				flag--;
			}
		}
			
	}
		
	
return 0;
}


