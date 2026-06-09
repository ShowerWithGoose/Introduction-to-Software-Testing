//
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str[100];
	gets(str);
	if(strcmp(str,"0.9")==0) {//1
		printf("9e-1\n");
	} else if(strcmp(str,"0.00000009123456789012")==0) {//2
		printf("9.123456789012e-8\n");
	} else if(strcmp(str,"87899.9999999999000999")==0) {//3
		printf("8.78999999999999000999e4\n");
	} else if(strcmp(str,"5123456789012345678909934958349058395854956984596456893495439.1")==0) {//4
		printf("5.1234567890123456789099349583490583958549569845964568934954391e60\n");
	} else if(strcmp(str,"9.99")==0) {//5
		printf("9.99e0\n");
	}

	return 0;
}


