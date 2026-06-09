#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long

int main()
{
	char num[500];
	gets(num);
	int n;
	//<1
	if(num[0]=='0'){
		int i=2;
		while(num[i]=='0')
		{
			i++;	
		}
		printf("%c",num[i]);
		n=i-1;
		i++;
		if(i!=strlen(num)){
			printf(".");
			for(;i<strlen(num);i++){
				printf("%c",num[i]);
			}
		}
		printf("e-%d",n);
	}
	//>1
	else {
		int i=1;
		printf("%c.",num[0]);
		while(num[i]!='.'){
			printf("%c",num[i]);
			i++;
		}
		n=i-1;
		i++;
		for(;i<strlen(num);i++){
			printf("%c",num[i]);
		}
			printf("e%d",n);
		
	}
	return 0;
}


