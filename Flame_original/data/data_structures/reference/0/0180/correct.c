#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main (){
	char s[100005];gets(s);
	int end=strlen(s)-1;
	for(int i=0;i<=end;i++){
	if(s[i]!='-'){	printf("%c",s[i]);}
	else {
		if(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z'))||((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')))
		{int k;
		for(k=s[i-1]+1;k<=s[i+1]-1;k++) printf("%c",k);
		}
		else printf("%c",s[i]);
	}	
	}
	return 0;
}

