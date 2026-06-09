#include<stdio.h>
#include<string.h> 
#include<ctype.h>
int main()
{
	char s[10005];
	gets(s);
	int i;
	char j;
	for(i=0;s[i]!='\0';i++){
		printf("%c",s[i]);
		if(s[i+1]=='-') {
			if(islower(s[i]) && islower(s[i+2]) && s[i]<s[i+2]){
				for(j=s[i]+1;j<s[i+2];j++){
					printf("%c",j);
				}
				i++;
			}
			else if(isupper(s[i]) && isupper(s[i+2]) && s[i]<s[i+2]){
				for(j=s[i]+1;j<s[i+2];j++){
					printf("%c",j);
				}
				i++;
			}
			else if(isdigit(s[i]) && isdigit(s[i+2]) && s[i]<s[i+2]){
				for(j=s[i]+1;j<s[i+2];j++){
					printf("%c",j);
				}
				i++;
			}
		}
	}
	return 0;
 } 



