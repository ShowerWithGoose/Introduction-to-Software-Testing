//第一周第一题
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char juzi[200];
	char shuchu;
	scanf("%s",juzi);
//	printf("%s",juzi);
	int i;
	int changdu;
	changdu= strlen(juzi);
//	printf("%d",changdu);
	for(i=0; i<changdu; i++) {
		if (juzi[i]== '-') {
			//	printf("123");
			//前是小写字母 ;后是小写字母，后面字母大于前面字母顺序
			if( juzi[i-1] >= 'a' && juzi[i-1] <= 'z' && juzi[i+1] >= 'a' && juzi[i+1] <= 'z' ) {
				//后面大于前面 则展开
				if( juzi[i+1] > juzi[i-1]) {
					for(shuchu=juzi[i-1]+1; shuchu<juzi[i+1]; shuchu++) {
						printf("%c",shuchu);
					}
				}
				//否则直接输出
				else
					printf("%c",juzi[i]);
			}
			//前是大写字母 ;后是大写字母，后面字母大于前面字母顺序
			else if( juzi[i-1] >= 'A' && juzi[i-1] <= 'Z' && juzi[i+1] >= 'A' && juzi[i+1] <= 'Z' ) {
				//后面大于前面 则展开
				if( juzi[i+1] > juzi[i-1]) {
					for(shuchu=juzi[i-1]+1; shuchu<juzi[i+1]; shuchu++) {
						printf("%c",shuchu);
					}
				}
				//否则直接输出
				else
					printf("%c",juzi[i]);
			}
			//前是较小数;后是较大数，后面数大于前面数字
			else if( juzi[i-1] >= '0' && juzi[i-1] <= '9' && juzi[i+1] >= '0' && juzi[i+1] <= '9' ) {
				//后面大于前面 则展开
				if( juzi[i+1] > juzi[i-1]) {
					for(shuchu=juzi[i-1]+1; shuchu<juzi[i+1]; shuchu++) {
						printf("%c",shuchu);
					}
				}
				//否则直接输出
				else
					printf("%c",juzi[i]);
			} 
			else printf("%c",juzi[i]);
		} else
			printf("%c",juzi[i]);

	}
	return 0;
}


