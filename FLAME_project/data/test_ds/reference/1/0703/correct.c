#include <stdio.h>
#include<string.h>
#include<ctype.h>
char s[10000000];
int main(){
	int i,len;
	gets(s);
	len=strlen(s);
	for(i=1;i<=len+2;i++){
		if(s[i]!='-'||(isupper(s[i-1])*isupper(s[i+1]))+(islower(s[i-1])*islower(s[i+1]))+(isdigit(s[i-1])*isdigit(s[i+1]))==0||s[i-1]>=s[i+1]){
			printf("%c",s[i-1]);
		}
		else{
			for(int j=0;j<s[i+1]-s[i-1];j++){
				printf("%c",s[i-1]+j);
			}
			i+=1;
		}
	}
	return 0;
}

