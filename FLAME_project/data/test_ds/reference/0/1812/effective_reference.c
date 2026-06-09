#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long
#define for_(i,m,n)  for(i=m;i<=(n);i++)

int main(void){
	char s[10000];
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]!='-'){
			printf("%c",s[i]);
		}else if((isupper(s[i-1])&&isupper(s[i+1]))||(islower(s[i-1])&&islower(s[i+1]))||(isdigit(s[i-1])&&isdigit(s[i+1]))){
			for(int c=s[i-1]+1;c<s[i+1];c++){
				printf("%c",c);
			}
		}else{
			printf("-");
		}
	}
	return 0;
}

