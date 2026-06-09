#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
int main(){
	char s[105],k;
	int i;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(s[i-1]<s[i+1]){
				if(islower(s[i-1])&&islower(s[i+1])||isupper(s[i-1])&&isupper(s[i+1])||isdigit(s[i-1])&&isdigit(s[i+1])){
					for(k=s[i-1]+1;k<s[i+1];k++){
						P("%c",k);
					}
				}
				else P("-");
			}
			else P("-");
		}
		else P("%c",s[i]);
	}
	return 0;
}



