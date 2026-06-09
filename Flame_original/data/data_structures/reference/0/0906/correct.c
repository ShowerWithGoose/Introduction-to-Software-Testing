#include <stdio.h>

int main(void) {
	char s[10000];
	char a,b;
	int i,j,k,f;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		f = 0;
		if(i>=1&&s[i]=='-'&&s[i+1]!='\0'){
			a = s[i-1];
			b = s[i+1];
			if('a'<=a&&a<='z'&&'a'<=b&&b<='z'&&a<b){
				for(k=1,j=b-a;k<j;k++){
					printf("%c",a+k);
				}
				f = 1;
			}
			if('A'<=a&&a<='Z'&&'A'<=b&&b<='Z'&&a<b){
				for(k=1,j=b-a;k<j;k++){
					printf("%c",a+k);
				}
				f = 1;
			}
			if('0'<=a&&a<='9'&&'0'<=b&&b<='9'&&a<b){
				for(k=1,j=b-a;k<j;k++){
					printf("%c",a+k);
				}
				f = 1;
			}
		}
	if(f==0)
		printf("%c",s[i]);
	}
	return 0;
}

