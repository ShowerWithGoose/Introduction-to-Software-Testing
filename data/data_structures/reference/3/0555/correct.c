#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	gets(s);
	int len=strlen(s);
	int i=0,j=0,k=0;
	if(s[i]=='0'&&s[i+1]=='.'){
		for(j=0;j<len;j++){
			if(s[2+j]!='0'){
				if(j==len-3){
					printf("%ce-%d",s[len-1],j+1);
					return 0;
				}
				else{
					printf("%c.",s[2+j]);
					for(k=3+j;k<len;k++){
						printf("%c",s[k]);
					}printf("e-%d",j+1);
					return 0;
				}
			}	
		}
	}
	if(s[0]!='0'&&s[1]=='.'){
		for(k=0;k<len;k++){
			printf("%c",s[k]);
		}printf("e0");
		return 0;
	}
	if(s[0]!='0'&&s[1]!='.'){
		for(k=0;k<len;k++){
			if(s[k]=='.'){
				break;
			}
		}
		printf("%c.",s[0]);
		for(j=1;j<len;j++){
			if(s[j]!='.'){
				printf("%c",s[j]);
			}
		}printf("e%d",k-1);
		return 0;
	}
 } 



