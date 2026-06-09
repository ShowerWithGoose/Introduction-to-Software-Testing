#include<stdio.h>
#include<string.h>
int main() {
	int i,l,j,flag=0;
	char str[105];
	gets(str);
	l=strlen(str)-1;
	if(str[0]=='0') {
		for(i=3; i<=l-1; i++) {
			if(str[i]!='0') flag=1;
		}
		if(flag==0){
			for(i=0; i<=l; i++) {
						if(str[i]!='0'&&str[i]!='.') {
							printf("%c",str[i]);
							for(j=i+1; j<=l; j++) 	printf("%c",str[j]);
							printf("e-");
							printf("%d",i-1);
							break;
						}
		}
		}
		
		else{
			for(i=0; i<=l; i++) {
						if(str[i]!='0'&&str[i]!='.') {
							printf("%c",str[i]);
							printf(".");
							for(j=i+1; j<=l; j++) 	printf("%c",str[j]);
							printf("e-");
							printf("%d",i-1);
							break;
						}
					}
		}
		
	} else {
		if(str[1]=='.') {
			for(i=0; i<=l; i++) {
				printf("%c",str[i]);
			}
			printf("e0");
		}

		else {
			printf("%c.",str[0]);
			for(i=1; i<=l; i++) {
				if(str[i]!='.') printf("%c",str[i]);
				else j=i;
			}
			printf("e%d",j-1);
		}
	}
	return 0;
}

