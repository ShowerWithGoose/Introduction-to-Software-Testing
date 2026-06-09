#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int judge(char c);
char putin[5];
int main(){
	int i = 0, x, y;
	char a;
	scanf("%c", &putin[i]); i++;
	while (scanf("%c", &putin[i]) != EOF){
		if (putin[i] != '-'){
			printf("%c", putin[(i + 2) % 3]);//输出前一个
			i = (i + 1) % 3;//向后一个
		}
		else{
			x = judge(putin[(i + 2) % 3]); a = putin[(i + 2) % 3];
			i = (i + 1) % 3;//向后一个
			scanf("%c", &putin[i]);
			y = judge(putin[i]);
			if (x != y){//不需要扩展
				printf("%c-", a);//打印-前一个和-，-后一个留给下次时打印
				i = (i + 1) % 3;
			}
			else{//可能需要扩展
				if (a >= putin[i]){
					printf("%c-", a);//打印-前一个和-，-后一个留给下次时打印
					i = (i + 1) % 3;
				}
				else{
					while (a < putin[i]){
						printf("%c", a);
						a++;
					}
					i = (i + 1) % 3;
				}
			}
		}
	}
	printf("%c", putin[(i + 2) % 3]);
	return 0;
}
int judge(char c){
	if (c >= 'a'&&c <= 'z')  return 1;
	else if (c >= 'A'&&c <= 'Z') return 2;
	else if(c>='0'&&c<='9') return 3;
}


