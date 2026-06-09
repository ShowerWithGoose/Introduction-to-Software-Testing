#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define ll long long
char s[M];
int main() {
	gets(s);
	int i,len=strlen(s);
	char j;
	for(i=0; i<len; i++) {
		if(isupper(s[i])&&s[i+1]=='-'&&isupper(s[i+2])) {
			for(j=s[i]; j<s[i+2]; j++) {
				printf("%c",j);
			}
			if(s[i+2]-s[i]>0)	i++;
		} else if(islower(s[i])&&s[i+1]=='-'&&islower(s[i+2])) {
			for(j=s[i]; j<s[i+2]; j++) {
				printf("%c",j);
			}
			if(s[i+2]-s[i]>0)	i++;
		} else if(isdigit(s[i])&&s[i+1]=='-'&&isdigit(s[i+2])) {
			for(j=s[i]; j<s[i+2];j++) {
				printf("%c",j);
			}
			if(s[i+2]-s[i]>0)	i++;
		}
		else{
			printf("%c",s[i]);
		}
	}

	return 0;
}



