#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main() {
	int i,j,k,x,y,z,n,m,cnt=0;
	char a[105];
	gets(a);
	if(a[0]=='0') {
		cnt=0;
		for(i=2; a[i]!='\0'; i++) {
			if(a[i]=='0') {
				cnt++;
			}
			if(a[i]!='0') {
				printf("%c",a[i]);
				if(a[i+1]!='\0') {
					printf(".");
				}
				for(i=i+1; a[i]!='\0'; i++) {
					printf("%c",a[i]);
				}
				printf("e-%d",cnt+1);
				break;
			}

		}
	}
	if(a[0]!='0'&&a[1]=='.') {
		for(i=0; a[i]!='\0'; i++) {
			printf("%c",a[i]);
		}
		printf("e0");
	}
	if(a[0]!='0'&&a[1]!='.') {
		cnt=0;
		printf("%c.",a[0]);
		for(i=1; a[i]!='\0'; i++) {
			if(a[i]!='.') {
				cnt++;
				printf("%c",a[i]);
			} else
				break;
		}
		for(i=i+1; a[i]!='\0'; i++) {
			printf("%c",a[i]);
		}
		printf("e%d",cnt);
	}







	return 0;
}


