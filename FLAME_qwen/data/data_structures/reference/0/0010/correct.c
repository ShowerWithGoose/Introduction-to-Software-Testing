#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>

int main()
{
	char s[1000];
	scanf("%s",&s);
	int i;
	char c;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='-'){
			if(s[i-1]>=97&&s[i+1]<=122&&s[i+1]>s[i-1]){
				for(c=s[i-1]+1;c<s[i+1];c++){
					printf("%c",c);
				}
			}
			else if(s[i-1]>=65&&s[i+1]<=90&&s[i+1]>s[i-1]){
				for(c=s[i-1]+1;c<s[i+1];c++){
					printf("%c",c);
				}
			}
			else if(s[i-1]>=48&&s[i+1]<=57&&s[i+1]>s[i-1]){
				for(c=s[i-1]+1;c<s[i+1];c++){
					printf("%c",c);
				}
			}
			else{
				printf("-");
			}
	}
		else{
			printf("%c",s[i]);
		} 
}
	return 0;
 
}





