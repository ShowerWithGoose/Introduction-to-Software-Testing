#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int i,j; 
	char  s[1001];
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='-'){
			if(isupper(s[i-1])&&isupper(s[i+1])&&s[i+1]>s[i-1]){
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);
			}else if(islower(s[i-1])&&islower(s[i+1])&&s[i+1]>s[i-1]){
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);
			}else if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i+1]>s[i-1]){
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);
			}else{
				printf("%c",s[i]);
		}
			}else{
				printf("%c",s[i]);
		}
	}
}

