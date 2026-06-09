#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
int main(){
	char s[500];
	int i,a,j;
	scanf("%s",&s[i]);
	a=strlen(s);
	for(i=0;i<a;i++){
		if(s[i]=='-'&&i>0&&i<a-1){
			
			if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1>s[i-1]])
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);
					
			else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1>s[i-1]])
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);
					
			else if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1>s[i-1]])
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);	
			else 
				printf("-");		
		}
		else
			printf("%c",s[i]);	
	}
	return 0;
} 




