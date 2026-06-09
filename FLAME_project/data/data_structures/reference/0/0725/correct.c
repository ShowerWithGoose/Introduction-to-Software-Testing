#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int main()
{
	char s[1000];
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(s[i-1]>='a'&&s[i-1]<='z'){
				if(s[i+1]>s[i-1]&&s[i+1]<='z'){
					for(int j=1;j<=(s[i+1]-s[i-1]-1);j++){
						printf("%c",s[i-1]+j);
					}
				}
				else{
					printf("-");
				}
			}
			if(s[i-1]>='A'&&s[i-1]<='Z'){
				if(s[i+1]>s[i-1]&&s[i+1]<='Z'){
					for(int j=1;j<=(s[i+1]-s[i-1]-1);j++){
						printf("%c",s[i-1]+j);
					}
				}
				else{
					printf("-");
				}
			}
			if(s[i-1]>='0'&&s[i-1]<='9'){
				if(s[i+1]>s[i-1]&&s[i+1]<='9'){
					for(int j=1;j<=(s[i+1]-s[i-1]-1);j++){
						printf("%c",s[i-1]+j);
					}
				}
				else{
					printf("-");
				}
			}
			continue;
		}
		printf("%c",s[i]);
	}
}




