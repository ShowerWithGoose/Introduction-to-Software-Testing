#include <stdio.h>
#define NUM 1001
int main(){
	char s[NUM];
	int i = 1,ch = 0;
	fgets(s,NUM - 1,stdin);
	printf("%c",s[0]);
	while(s[i] != '\0'){
		if(s[i] == '-'){
			if(s[i-1] >= '0'&&s[i-1] <= '9'&&s[i+1] >= '0'&&s[i+1] <= '9'&&s[i+1] > s[i-1]){
				for(ch = s[i-1] + 1;ch <= s[i+1];ch++){
					printf("%c",ch);
				}
			}
			else if(s[i-1] >= 'A'&&s[i-1] <= 'Z'&&s[i+1] >= 'A'&&s[i+1] <= 'Z'&&s[i+1] > s[i-1]){
				for(ch = s[i-1] + 1;ch <= s[i+1];ch++){
					printf("%c",ch);
				}
			}
			else if(s[i-1] >= 'a'&&s[i-1] <= 'z'&&s[i+1] >= 'a'&&s[i+1] <= 'z'&&s[i+1] > s[i-1]){
				for(ch = s[i-1] + 1;ch <= s[i+1];ch++){
					printf("%c",ch);
				}
			}
			else{
				printf("%c%c",s[i],s[i+1]);
			}
			i+=2;
		}
		else{
			printf("%c",s[i]);
			i++;
		}
	}
	return 0;
}


