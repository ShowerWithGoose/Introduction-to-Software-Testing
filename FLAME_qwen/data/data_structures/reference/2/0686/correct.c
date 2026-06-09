#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 100000



char input[M];

int change[M];

int s[M];
int top = 0;

void zhengli(){
	int a = 0;
	for(int i = 0; input[i]!='='; i++){
		if(input[i]<='9'&&input[i]>='0'){
			int tmp = input[i]-'0';
			for(int k=1; input[i+k]<='9'&&input[i+k]>='0'; i++){
				tmp = tmp*10 + input[i+k]-'0';
			}
			change[a++] = tmp;
		}
		else if(input[i] == '+')
			change[a++] = -1;
		else if(input[i] == '-')
			change[a++] = -2;
		else if(input[i] == '*')
			change[a++] = -3;
		else if(input[i] == '/')
			change[a++] = -4;
	}
	change[a] = -5;
}

void chengyuchu(){ //优先计算乘除，将没进行运算的数字与符号计入stack 
	int i = 0;
	for(i; change[i]!=-5; i++){
		if(change[i] == -3){
			s[--top] = (s[top++]) * change[i+1];
			i++;
		}
		else if(change[i] == -4){
			s[--top] = s[top++] / change[i+1];
			i++;
		}
		else{
			s[top++] = change[i];
		}
	}
	s[top] = -5;	
}  

int jiayujian(){
	int sum = s[0];
	for(int i=1; s[i]!=-5; i+=2 ){
		if(s[i] == -1)
			sum+=s[i+1];
		else
			sum-=s[i+1];
	}
	return sum;
}

int main(){
	gets(input);
	zhengli();
	chengyuchu();
	printf("%d", jiayujian());
	
}

