#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define eps 1e-6
int main(void)
{
	char a[100003];
	scanf("%s",a);
	int len = strlen(a) - 1;
	int i,j,num;
	if(a[0] != '0'&&a[1] == '.')	printf("%se0",a);
	else if(a[0] == '0'){
		num = 0;
		for(i = 2;;i ++){
			num ++;
			if(a[i] != '0')
			break;
		}
		if(a[i + 1] == '\0') printf("%c",a[i]);
		else printf("%c.",a[i]);
		for(j = i + 1;j <= len;j ++){
			printf("%c",a[j]);
		}
		printf("e-%d",num);
	}
	else {
		num = 0;
		for(i = 0;;i ++){
			num ++;//num - 2
			if(a[i]=='.') break;
		}
		printf("%c.",a[0]);
		for(j = 1;j <= len;j ++){
			if(a[j]=='.')	continue;
			printf("%c",a[j]);
		}
		printf("e%d",num - 2);
	}
	return 0;
}

