#include <stdio.h>
#include <string.h>
int main() {
	char a[100]={'\0'};
	int i,j=0,k;
	scanf("%s",a);
	if(a[1]=='.' && a[0]=='0'){
		for(i=0;i<strlen(a);i++){
			if(a[i] == '0'){
				j++;
			}
			else if(a[i]!='0' && a[i]!='.')
				break;
		}
		printf("%c",a[i]);
		if(a[i+1] != '\0'){
			printf(".");
		}
		for(k=i+1;k<strlen(a);k++){
			printf("%c",a[k]);
		}
		printf("e-%d",j);
	}
	else if(a[1]=='.' && a[0]!='0'){
		for(i=0;i<strlen(a);i++){
			printf("%c",a[i]);
		}
		printf("e0");
	}
	else{
		for(i=0;i<strlen(a);i++){
			if(a[i]=='.'){
				j = i-1;
				break;
			}
		}
		printf("%c.",a[0]);
		for(i=1;i<strlen(a);i++){
			if(a[i] != '.'){
				printf("%c",a[i]);
			}
		}
		printf("e%d",j);
	}
	return 0;
}

