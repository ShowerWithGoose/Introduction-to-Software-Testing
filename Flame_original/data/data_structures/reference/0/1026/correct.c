#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char s[100];
	int i=0;
	int len;
	scanf("%s",s);
	while(s[i]!='\0'){
		if(s[i]!='-'){
			printf("%c",s[i]);
			i++;
		}
		else{
			if(s[i-1]<='z'&&s[i-1]>='a'){
				if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1]){
					len=s[i+1]-s[i-1];
					while(len>1){
						printf("%c",s[i+1]-len+1);
						len--;
					}
				}
				else
				printf("%c",s[i]);
				i++;
			}
			else if(s[i-1]<='Z'&&s[i-1]>='A'){
				if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1]){
					len=s[i+1]-s[i-1];
					while(len>1){
						printf("%c",s[i+1]-len+1);
						len--;
					}
				}
				else
				printf("%c",s[i]);
				i++;
			}
			else if(s[i-1]<='9'&&s[i-1]>='0'){
				if(s[i+1]<='9'&&s[i+1]>='0'&&s[i+1]>s[i-1]){
					len=s[i+1]-s[i-1];
					while(len>1){
						printf("%c",s[i+1]-len+1);
						len--;
					}
				}
				else
				printf("%c",s[i]);
				i++;
			}
		}
	}
	return 0;
}



