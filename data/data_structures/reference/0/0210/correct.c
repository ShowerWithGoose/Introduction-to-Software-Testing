#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define eps 1e-6

char buf[BUFSIZ];
int get_type(char a)
{
	if(isdigit(a)) return 1;
	if(islower(a)) return 2;
	if(isupper(a)) return 3;
	return 0;
}

char s[10000000];
int main()
{
	scanf("%[^\n]",s); //strlen no '\0' 
	int i=0;
	for(;i<strlen(s);i++){
		if(s[i+1]!='-') printf("%c",s[i]);
		else{
			if(get_type(s[i]) != get_type(s[i+2]) || get_type(s[i])==0){
				printf("%c",s[i]);
			}else if(s[i]>=s[i+2]){
				printf("%c",s[i]);
			}else{
				printf("%c",s[i]);
				int j;
				for(j=1;s[i]+j < s[i+2];j++){
					printf("%c",s[i]+j);
				}
				i++;
			}
		}
	}
	return 0;
}





