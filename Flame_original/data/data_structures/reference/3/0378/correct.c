#include <stdio.h> 
#include <string.h>
int main()
{
	char s[10000];
	int i,fl,l;
	gets(s);
	l=strlen(s);
	for(i=0;s[i]!='.' && s[i]!='\0';i++);
	fl=i;
	if(fl && s[fl-1]=='0'){
		for(i=i+1;s[i]=='0';i++);
		fl=-i+1;
		putchar(s[i]);
		if(i==l-1);
		else{
			putchar('.');
			i++;
			for(;s[i]!='\0';i++){
				putchar(s[i]);
			}
		}
		printf("e%d",fl);
	}else{
		putchar(s[0]);
		putchar('.');
		for(i=1;s[i]!='\0';i++){
			if(i==fl);
			else{
				putchar(s[i]);
			}
		}
		printf("e%d",fl==l?fl:fl-1);
	}
	return 0;
}

