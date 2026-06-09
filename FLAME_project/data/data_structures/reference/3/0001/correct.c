#include<stdio.h>
#include<string.h>

int main(){
	char s[110];
	scanf("%s", s);
	int len = strlen(s);
	int i, dot_position = 0;
	for(i = 0; i < len; i++){
		if(s[i] == '.'){
			dot_position = i;
			break;
		}
	}
	int index = 0;
	if(dot_position == 1 && s[dot_position - 1] == '0'){
		for(i = dot_position + 1; i < len; i++){
			if(s[i] == '0'){
				index++;
			}else{
				printf("%c", s[i]);
				break;
			}
		}
		if(i != len - 1){
			printf(".");
			for(i += 1; i < len; i++){
				printf("%c", s[i]);
			}
		}
		printf("e-%d\n", index + 1);
	}else{
		printf("%c.", s[0]);
		index = dot_position - 1;
		for(i = 1; i < len; i++){
			if(s[i] != '.'){
				printf("%c", s[i]);
			}
		}
		printf("e%d\n", index);
	}
	
	return 0;
} 

