#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char putin[1000];//i
int postfix[1000];//后缀表达式 j
int stack[1000];//符号栈,k(+:-1,-:-2,*:-3,/:-4)
int putout[1000];//m
int change(char c);
int cal(int x, int y, int a);
int main(){
	int len,i=0,j=0,k=0,m=0, flag=0;
	gets(putin);
	while (putin[i] != '=')
	{
		if (putin[i] == ' ') i++;//空格跳过
		else if (putin[i] >= '0'&& putin[i] <= '9'){
			//数字进入后缀表达式
			if (putin[i - 1] >= '0'&& putin[i - 1] <= '9'){
				j--;
				postfix[j] = 10 * postfix[j] + putin[i] - '0';
			
			}
			else postfix[j] = putin[i] - '0';
			j++; i++;
		}
		else
		{//符号的情况
			if (flag == 0){
				stack[k] = change(putin[i]); flag = 1;
			}
			else{
				if (putin[i] == '+' || putin[i] == '-'){//要清空栈
					while (k >= 0){
						postfix[j] = stack[k]; j++; k--;
					}
					k++;
					stack[k] = change(putin[i]);//再把现在的存进去
				}
				else{//也就是要存入*/
					if (stack[k] == -1 || stack[k] == -2){//栈顶是+-
						k++;
						stack[k] = change(putin[i]);
					}
					else{//栈顶是乘除
						while (stack[k] == -3 || stack[k] == -4){
							postfix[j] = stack[k]; j++; k--;
						}
						k++;
						stack[k] = change(putin[i]);
					}
				}
			}
			i++;
		}
	}

	//最后把栈里剩下的都输出
	while (k >= 0){
		postfix[j] = stack[k]; j++; k--;
	}
	len = j;
	for (j = 0; j < len; j++){
		if (postfix[j] >= 0){
			putout[m] = postfix[j]; m++;
		}
		else{
			putout[m-2]=cal(putout[m - 2], putout[m - 1], postfix[j]);
			m--;
		}
	}
	printf("%d", putout[0]);
	return 0;
}
int change(char c){
	if (c == '+') return -1;
	else if (c == '-')  return -2;
	else if (c == '*') return -3;
	else if (c == '/') return -4;
}

int cal(int x, int y, int a){
	if (a == -1) return (x + y);
	else if (a == -2) return (x - y);
	else if (a == -3) return (x*y);
	else if (a == -4) return ((int)x / y);
}


