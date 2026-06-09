#include <stdio.h>
#include <string.h>

char a[1000];
char b[1000];
int main()
{
	int intlen;
	
	gets(a);
	int len = strlen(a);
	int nozero = strspn(a+2, "0");
	int flag = 1;
	if (a[0] == '0'){
		if (nozero+3==len) flag = 0;
	
		b[0] = a[nozero+2];
		if(flag) b[1] = '.';
		strcat(b, a+nozero+3);
		printf("%se-%d", b, nozero+1);
	}
	else {
		char *p = strchr(a, '.');
		intlen = p - a;
		*p = 0;
		strcat(a, a+intlen+1);
		b[0] = a[0];
		b[1] = '.';
		strcat(b, a+1);
		//	printf("%d\n", nozero);
		printf("%se%d", b, intlen - 1);
	}
}
