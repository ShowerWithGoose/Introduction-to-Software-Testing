#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int main() {
	char s,s0,s1;
	while(scanf("%c",&s)!=EOF){
		if(s!='-') {
			printf("%c",s);
			s0=s;
		}
		else{
			scanf("%c",&s1);
			if(islower(s0)&&islower(s1)&&s0<s1){
				s0++;
				while(s0<=s1){
					printf("%c",s0);
					s0++;
				}
				s0=s1;
			}
			else if(isupper(s0)&&isupper(s1)&&s0<s1){
				s0++;
				while(s0<=s1){
					printf("%c",s0);
					s0++;
				}
				s0=s1;
			}
			else if(isdigit(s0)&&isdigit(s1)&&s0<s1){
				s0++;
				while(s0<=s1){
					printf("%c",s0);
					s0++;
				}
				s0=s1;
			}
			else{
				printf("-%c",s1);
				s0=s1;
			}
		}
	}
	return 0;
}




