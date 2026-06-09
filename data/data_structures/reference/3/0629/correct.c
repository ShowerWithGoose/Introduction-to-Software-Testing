#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char s[105];
	int i=0,j=0,len=0;
	gets(s);
	len=strlen(s);
	if(s[1]=='.'&&s[0]=='0') {
		for(i=2; s[i]=='0'; i++)
			j++;
		if(j==len-3) printf("%ce-%d\n",s[len-1],j+1);
		else {
			printf("%c.",s[j+2]);
			for(i=j+3; i<len; i++) printf("%c",s[i]);
			printf("e-%d\n",j+1);
		}
	} else {
		printf("%c.",s[0]);
		for(i=1; i<len; i++) {
			if(s[i]=='.') j=i;
			else printf("%c",s[i]);
		}
		printf("e%d\n",j-1);
	}
	return 0;
}



