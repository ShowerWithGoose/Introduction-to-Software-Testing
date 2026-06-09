#include<stdio.h>
#include<string.h>

int main(){
	char str[101] = {0};
	int i;
	int sign1 = -1,	sign2,	up;
	
	scanf("%s",str);
	for(i = 0;str[i] != '\0';++i){
		if(str[i] == '.'){
			sign2 = i;
		}else if(sign1 == -1){
			if(str[i] != '0'){
				sign1 = i;
			}
		} 
		
	}
	
	if(sign1 == 0){
		up = sign2-sign1-1;
	
		printf("%c",str[0]);
		printf(".");
		
		for(i = 1;i <= sign2-1;++i){
			printf("%c",str[i]);
		}
		
		for(i = sign2+1;str[i] != '\0';++i){
			printf("%c",str[i]);
		}
		
		printf("e");
		printf("%d",up);
	}else{
		up = sign2-sign1;
		
		printf("%c",str[sign1]);
		if(sign1+1 != strlen(str))
		printf(".");
									
		for(i = sign1+1;str[i] != '\0';++i){
			printf("%c",str[i]);
		}
		
		printf("e");
		printf("%d",up);
	}
	return 0;
}
