#include<stdio.h>
#include<string.h> 
char s[100002];
int d[100002];
int main() {
	scanf("%s", s);
	int l = strlen(s), i, res = 0;
	for(i = 0; i < l; ++ i)
		if(s[i] == '.') res = i - 1;
	i = 0;
	if(s[0] != '0') {
		printf("%c", s[0]);
		if(i != l - 1) printf(".");
		for(i = 1; i < l; ++ i)
			if(s[i] != '.') printf("%c", s[i]);
	} else {
		i = 2;
		while(s[i] == '0') ++ i, -- res;
		res --;
		printf("%c", s[i ++]);
		if(i != l) printf(".");
		for( ; i < l; ++ i) printf("%c", s[i]);
	}
	printf("e%d", res);
	return 0;
}
/*
5 - 1 * 2 * 3 + 12 / 2 / 2  =

*/



