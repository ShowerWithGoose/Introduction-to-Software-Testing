#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
char s[100];
int main()
{
	gets(s);
	int i,j;
	int lens=strlen(s);
	for(i=0;i<lens;i++){
		if(s[i]=='-'){
			if(islower(s[i-1])&&islower(s[i+1])&&s[i+1]>s[i-1]){
				for(j=1;j<s[i+1]-s[i-1];j++){
					putchar(s[i-1]+j);
				}
			}
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i+1]>s[i-1]){
				for(j=1;j<s[i+1]-s[i-1];j++){
					putchar(s[i-1]+j);
				}
			}
			else if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i+1]>s[i-1]){
				for(j=1;j<s[i+1]-s[i-1];j++){
					putchar(s[i-1]+j);
				}
			}
			else putchar(s[i]);
		}
		else putchar(s[i]);
	}
	
}


