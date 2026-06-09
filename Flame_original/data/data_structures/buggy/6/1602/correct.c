#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{	long long int st[100]={0};
	int a,i=0;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			
			
			if(i==100)printf("error ");
			else
			scanf("%lld ",&st[i++]);
		}
		else if(a==0){
			
			
			if(i==0)printf("error ");
				else{
				printf("%lld ",st[--i]);
				}
			
		}
		else if(a==-1){
			return 0;
		}
		
	}
return 0;
}

