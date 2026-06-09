#include <stdio.h>
#include <string.h>
int main()
    {
    	char s[100];
    	int i=0,j;
    	scanf("%s",s);
        if(s[i]=='0'){
        	i=2;
        	while(s[i]=='0') i++;
        	printf("%c",s[i]);
        	if(s[i+1]!='\0'){
        		printf(".");
        		for(j=i+1;s[j]!='\0';j++) printf("%c",s[j]);
			}
			printf("e-%d",i-1);
		}
		else{
			while(s[i]!='.') i++;
			printf("%c.",s[0]);
			for(j=1;s[j]!='\0';j++)
			{
				if(s[j]!='.') printf("%c",s[j]);
			}
			printf("e%d",i-1);
		}
		return 0;
	 } 

