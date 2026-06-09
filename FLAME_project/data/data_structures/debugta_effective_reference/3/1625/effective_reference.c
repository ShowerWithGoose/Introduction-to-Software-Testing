#include<stdio.h>
#include<string.h>

int s(int n, int k);

int len;

int main(){
	//int num, num1, num01 = 0, num02 = 0, k = 0/*num1的位数相关*/;
	int first_i = 0, flag = 0;
	char num1[500] = {'\0'}, hold;
	char num2[500] = {'\0'};
	scanf("%c", &hold);
	if(hold == '-')
		flag = 1;
	else{
		num1[0] = hold;
		first_i = 1;
	}
	for(; num1[first_i - 1] != '.'; first_i ++){
		scanf("%c", &num1[first_i]);
	}
	first_i --;
	num1[first_i] = '\0';
	gets(num2);
	len = strlen(num2);
	if(flag == 0){
		if(num1[0] == '0'){
			for(int i = 0; i < len; i ++){
				if(num2[i] != '0'){	
					printf("%c", num2[i]);
					if(i == len - 1)
						goto X;
					printf(".");
					for(int q = i + 1; q < len; q ++){
						printf("%c", num2[q]);
					}
X :					printf("e-");
					printf("%d", i + 1);
					return 0;
				}
			}
		}
		else if(num1[0] != '0' && first_i == 1){
			printf("%c.", num1[0]);
			for(int j = 0; j < len; j ++){
				printf("%c", num2[j]);
			}
			printf("e0\n");
		}
		else{
			printf("%c.", num1[0]);
			for(int t = 1; t < first_i; t ++){
				printf("%c", num1[t]);
			}
			for(int r = 0; r < len; r ++){
				printf("%c", num2[r]);
			}
			printf("e%d\n", first_i - 1);
		} 
	}
	else if(flag == 1){
		printf("-");
		if(num1[0] == '0'){
		for(int i = 0; i < len; i ++){
			if(num2[i] != '0'){
				printf("%ce-", num2[i]);
				printf("%d\n", i + 1);
				}
			}
		}
		else if(num1[0] != '0' && first_i == 1){
			printf("%c.", num1[0]);
			for(int j = 0; j < len; j ++){
				printf("%c", num2[j]);
			}
			printf("e0\n");
		}
		else{
			printf("%c.", num1[0]);
			for(int t = 1; t < first_i; t ++){
				printf("%c", num1[t]);
			}
			for(int r = 0; r < len; r ++){
				printf("%c", num2[r]);
			}
			printf("e%d\n", first_i - 1);
		} 
	}
	return 0;
}

int s(int n, int k){
	int S = 1;
	for(int s = k; s > 0; s --){
	S *= n;	
	}
	return S;
}



