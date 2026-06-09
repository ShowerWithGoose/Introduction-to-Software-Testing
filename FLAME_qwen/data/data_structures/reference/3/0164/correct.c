#include <stdio.h>
#include <string.h>
int main()
{
	char ch[103];
	int i = 0, j = 0, k = 0, l = 0;
	scanf("%s", ch);
	while(i < strlen(ch)){
		if(ch[i] == '.'){
			j = i;
			k = 1;
		}
		i++;
	}
	if(k == 1){//有小数点 
		if(ch[0] == '0'){//数小于一 
			for(i = j + 1; i < strlen(ch); i++){
				if(ch[i] != '0'){
					l = i;
					break;
				}
			}
			printf("%c", ch[l]);
			if(l != strlen(ch)-1){
				printf(".");
				for(i = l+1; i < strlen(ch); i++){
					printf("%c", ch[i]);
				}
			}
			printf("e-%d", l - 1);
		}else{//数大于1 
			printf("%c.", ch[0]);
			for(i = 1; i < strlen(ch); i++){
				if(ch[i] != '.'){
					printf("%c", ch[i]);
				}
			}
			printf("e%d", j-1);
		}
	}else{//无小数点 
		if(strlen(ch) == 1){//一位整数 
			printf("%ce0", ch[0]);
		}else{//两位及以上整数 
			printf("%c.", ch);
			for(i = 1; i < strlen(ch); i++){
				printf("%c", ch[i]);
			}
			printf("e%d", strlen(ch)-1);
		}
	}
	return 0;
 } 

