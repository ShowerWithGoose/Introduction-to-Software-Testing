//用0123456789代替12345678910 
#include<stdio.h>
#include<string.h>

void num_judg(char ch[]);
void char_to_int(char num[]);
void int_to_char(long m);
long max(long n);
 
long n, m = 0, sum = 0;//strlen(ch) == n
char nchet[10] = {'\0'}, chet[10] = {'\0'};
int flag; 
long maax; 

int main(){
	scanf("%ld", &n);
	if(n == 1){
		printf("1\n");
		return 0;
	}
	for(int i = 0; i < n; i ++){
		chet[i] = n - 1 - i + '0';
	}
	char_to_int(chet);
	sum = m;
	maax = max(n);
	while(sum <= maax){
		m = sum;
		int_to_char(m);
		num_judg(chet);
		if(flag == 1){
			for(int j = n - 1; j > 0; j --){
				printf("%c ", (chet[j] + 1));
			}
			printf("%c\n", chet[0] + 1);
		}
		sum ++;
	}
	return 0;
}

void num_judg(char ch[]){
	int r = 0;
	for(int i = 0; i < n; i ++){
		nchet[i] = '\0';
	}
	for(int i = 0; i < n; i ++){
		r = (int)ch[i] - '0';
		nchet[r] = '1';
	}
	for(int i = 0; i < n; i ++){
		if(nchet[i] != '1'){
			flag = -1;
			return;
		}
	}
	flag = 1;
	return;
}

void char_to_int(char num[]){
	for(int i = n - 1; i >= 0; i --){//数字的低位放在字符串的低位 
		m = m * 10 + num[i] - '0';
	} 
}

void int_to_char(long m){
	for(int i = 0; m > 0; i ++){
		chet[i] = m % 10 + '0';
		m /= 10;
	}
}

long max(long n){
	long mi = n - 1;
	for(int i = 0; i < n - 1; i ++){
		mi = mi * 10 + n - 2 - i;
	}
	return mi;
} 



