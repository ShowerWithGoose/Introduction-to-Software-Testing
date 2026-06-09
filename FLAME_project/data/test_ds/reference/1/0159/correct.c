#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char s[100];

int main() {
	int i,j;
	//freopen("in.txt","r",stdin);
	fgets(s,100,stdin);
	for(i=0; i<strlen(s); i++) {
		if(s[i]!='-')
			printf("%c",s[i]);
		else {


			if((isdigit(s[i-1])&&isdigit(s[i+1]))||(islower(s[i-1])&&islower(s[i+1]))||(isupper(s[i-1])&&isupper(s[i+1]))) {
				for(j=s[i-1]+1; j<s[i+1]; j++) {
					printf("%c",j);
				}
			} else {
				printf("-");


			}

		}

	}

	return 0;
}

