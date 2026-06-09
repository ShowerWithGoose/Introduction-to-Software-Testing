#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
//int·¶Î§£º2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}

int main(){
	char str[1007];
	int location = 0,mark = 0;
	gets(str);
	for(int i = 0 ; str[i] != '\0' ; i++){
		if(str[i] == '.' ) location = i;
	}
	if(location > 1){
		printf("%d.",str[0] - '0');
		for(int i = 1;str[i] != '\0';i++){
			if(str[i] == '.') continue;
			printf("%d",str[i] - '0');
		}
		printf("e%d", location - 1);
	}
	else if(location == 1){
		if(str[0] != '0'){
			printf("%d.",str[0] - '0');
					for(int i = 1;str[i] != '\0';i++){
						if(str[i] == '.') continue;
						printf("%d",str[i] - '0');
					}
					printf("e%d", location - 1);
		}
		else{
			for(int i = location ; str[i] != '\0' ; i++){
					if(str[i] != '0' && str[i] != '.' ) {
					mark = i;
					break;}
				}
			if(mark == strlen(str) - 1) printf("%d",str[mark] - '0');
			else printf("%d.",str[mark] - '0');
			for(int i = mark + 1;str[i] != '\0';i++){
					printf("%d",str[i] - '0');
					}
			printf("e-%d", mark - 1);
		}
	}
	return 0;	
	}

