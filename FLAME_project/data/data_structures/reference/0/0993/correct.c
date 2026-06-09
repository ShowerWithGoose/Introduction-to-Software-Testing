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
	int i,j;
	for(j = 0;j <= len;j ++){
		if(a[j]=='-'&&(a[j - 1] >= 'a'&&a[j - 1] <= 'z')&&(a[j + 1] >= 'a'&&a[j + 1] <= 'z')&&a[j + 1] > a[j - 1]){
			for(i = a[j - 1] + 1;i <= a[j + 1] - 1;i ++){
				printf("%c",i);
			}
		}
		else if(a[j]=='-'&&(a[j - 1] >= 'A'&&a[j - 1] <= 'Z')&&(a[j + 1] >= 'A'&&a[j + 1] <= 'Z')&&a[j + 1] > a[j - 1]){
			for(i = a[j - 1] + 1;i <= a[j + 1] - 1;i ++){
				printf("%c",i);
			}
		}
		else if(a[j]=='-'&&(a[j - 1] >= '0'&&a[j - 1] <= '9')&&(a[j + 1] >= '0'&&a[j + 1] <= '9')&&a[j + 1] > a[j - 1]){
			for(i = a[j - 1] + 1;i <= a[j + 1] - 1;i ++){
				printf("%c",i);
			}
		}
		else printf("%c",a[j]);
	}
	return 0;
}



