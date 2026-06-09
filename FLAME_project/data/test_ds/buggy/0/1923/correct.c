#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))

char s[1000];
int main()
{
	int i;
	char c; 
	fgets(s,sizeof(s),stdin);
	for(i=0; i<strlen(s); i++){
		c='0';
		if(s[i] == '-'){
			if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){
				c=s[i-1];
				while(c<s[i+1]-1){
					c=c+1;
					printf("%c",c);
				}
			}
			else if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){
				c=s[i-1];
				while(c<s[i+1]-1){
					c=c+1;
					printf("%c",c);
				}
			}
			else if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){
				c=s[i-1];
				while(c<s[i+1]-1){
					c=c+1;
					printf("%c",c);
				}
			}
			else{
				printf("-");
			}
		}
		else(printf("%c",s[i]));
	}
	return 0;
}



