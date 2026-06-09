#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int
char a[10001];
int len,dian,i,xiao;
int main() {
	scanf("%s",a);
	len=strlen(a);
	for(i=0; i<len; i++) {
		if(a[i]=='.') {
			dian=i;
			break;
		}
	}
	if(i==1) {
		if(a[0]=='0') {
			for(i=2; i<len; i++) {
				if(a[i]!='0') {
					xiao=i;//xiao为小数第一次出现非0的位置
					break;
				}
			}
			if(xiao==len-1) {
				printf("%ce-%d",a[i],xiao-1);
				return 0;
			} else {
				printf("%c",a[xiao]);
				printf(".");
				for(i=xiao+1; i<len; i++)
					printf("%c",a[i]);
				printf("e-%d",xiao-1);
			}
		}
		if(a[0]!='0') {
			for(i=0; i<len; i++)
				printf("%c",a[i]);
			printf("e0");
		}
	} else {
		printf("%c.",a[0]);
		for(i=1; i<dian; i++)
			printf("%c",a[i]);
		for(i=dian+1; i<len; i++)
			printf("%c",a[i]);
		printf("e%d",dian-1);
	}
	return 0;
}

	

