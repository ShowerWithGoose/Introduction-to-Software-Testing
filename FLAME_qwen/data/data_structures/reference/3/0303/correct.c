#include <stdio.h>
#include <string.h>

char s[10000];

int main(){
	gets(s);
	int n = strlen(s);
	int zeroed = 0;
	int doti = -1;
	int digit = 0;
	int start = -1;
	int doted = 0;
	for(int i=0; i<n; i++){
		if(s[i] == '.'){
			doti = i; 
			continue;
		}else
			digit += zeroed;
		
		if(s[i] != '0' && !zeroed){
			zeroed = 1;
			start = i;
			printf("%c", s[i]);
		}else if(zeroed){
			if(!doted){
				printf(".");
				doted = 1;
			}
			printf("%c", s[i]);
		}
	}
	if(doti-start-1 < 0)
		printf("e%d", doti-start);
	else
		printf("e%d", doti-start-1);
	
	return 0;
}

