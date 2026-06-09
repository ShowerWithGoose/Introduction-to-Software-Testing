#include <stdio.h>
#include <string.h>

int main(void) {
	char s[120];
	int m;
	scanf("%s",s);
	if(s[0]=='0'){
		for(int i=0;s[i]!='\0';i++){
			if(s[i]!='0'&&s[i]!='.'){
				if(s[i+1]!='\0'){
					printf("%c.",s[i]);
					for(int j=i+1;j<strlen(s);j++){
						printf("%c",s[j]);
					}
				}
				else
					printf("%c",s[i]);
			m = i;
			break;
			}
		}
		printf("e-%d",m-1);
	}
	else{
		for(int i=0;s[i]!='\0';i++){
		if(s[i]=='.'&&s[0]!='0'){
			for(int k=0;k<strlen(s);k++){
				if(k==1){
					printf(".");
				}
				if(k!=i){
					printf("%c",s[k]);
				}
			}
			printf("e%d",i-1);
		}
	}
		
	}
	

	return 0;
}

