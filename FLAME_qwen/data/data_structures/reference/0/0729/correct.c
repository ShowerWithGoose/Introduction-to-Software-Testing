#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
void give(char x,char y){
	do{
		printf("%c",x);
		x++;
	} while(x<=y);
}
int main()
{
	char s[5000];
	gets(s);
	
	int i=0;

	for (;s[i]!='\0';i++){
		if(s[i]=='-'&&s[i-1]<s[i+1]){
			if(((s[i-1]<='z'&&s[i-1]>='a')&&(s[i+1]<='z'&&s[i+1]>='a'))||((s[i-1]<='9'&&s[i-1]>='0')&&(s[i+1]<='9'&&s[i+1]>='0'))||((s[i-1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='Z'&&s[i+1]>='A')))
			give(s[i-1]+1,s[i+1]-1);
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}




